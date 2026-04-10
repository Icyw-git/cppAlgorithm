#include<iostream>
using namespace std;

template <class elemtype>
class linklist
{
    struct Node
    {
        elemtype data;
        Node* next;

        Node(elemtype data_ = 0)
        {
            data = data_;
            next = nullptr;
        }
    };

    Node* head;
    int length;

public:
    linklist()
    {
        head = new Node();
        length = 0;
    }

    ~linklist()
    {
        Node* p = head->next;
        Node* q = head;
        head->next = nullptr;
        while (q != nullptr)
        {
            q = p->next;
            delete p;
            p = q;
        }
        length = 0;
    }

    void show()
    {
        Node* p = head;
        while (p->next != nullptr)
        {
            p = p->next;

            cout << p->data << ' ';
        }
    }

    void inserttail(elemtype val)
    {
        Node* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        Node* tem = new Node(val);
        p->next = tem;
        length++;
    }

    void crossfind(const linklist& c1, const linklist& c2)
    {
        int size = 0;
        Node* p = c1.head;
        Node* q = c2.head;
        if (c1.length > c2.length)
        {
            size = c1.length - c2.length;
            while (size > 0)
            {
                p = p->next;
                size--;
            }
            while (p != nullptr && q != nullptr)
            {
                if (p != q)
                {
                    q = q->next;
                    p = p->next;
                }
                else
                {
                    cout << p->data << endl;
                    return;
                }
            }
        }
    }

    elemtype getlastkval(int k)
    {
        Node* p = head;
        Node* q = head;
        for (int i = 0; i < k - 1; i++)
        {
            while (p->next != nullptr)
            {
                p = p->next;
            }
        }
        while (p->next != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        return q->data;
    }

    void merge(linklist& c1, linklist& c2)
    {
        Node* p = c1.head->next;
        Node* q = c2.head->next;
        Node* s = c1.head;
        c2.head->next = nullptr;
        while (p != nullptr && q != nullptr)
        {
            if (p->data > q->data)
            {
                s->next = q;
                q = q->next;
                s = s->next;
            }
            else
            {
                s->next = p;
                p = p->next;
                s = s->next;
            }
        }
        if (p != nullptr)
        {
            s->next = p;
        }
        if (q != nullptr)
        {
            s->next = q;
        }
    }

    bool cycle()
    {
        Node* p = head;
        Node* q = head;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            p = p->next->next;
            q = q->next;
            if (p == q)
            {
                p = head;
                while (p != q)
                {
                    p = p->next;
                    q = q->next;
                }

                return true;
            }
        }
        return false;
    }
};

template <class elemtype>
class doublelinklist
{
    struct Node
    {
        elemtype data;
        elemtype* prev;
        elemtype* next;

        Node(elemtype data_ = 0)
        {
            data = data_;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int length = 0;

public:
    doublelinklist()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~doublelinklist()
    {
        Node* p = head->next;
        Node* q = head;
        head->next = nullptr;
        while (p != nullptr)
        {
            q = p->next;
            delete p;
            p = q;
        }
        delete head;
        length = 0;
    }

    void insert(int i, elemtype val)
    {
        Node* p = head;
        while (i > 0)
        {
            p = p->next;
            i--;
        }
        Node* q = new Node(val);
        q->next = p;
        p->prev->next = q;
        p->prev = q;
        length++;
    }
};


int main()
{
    linklist<int> a;
    linklist<int> b;
    a.inserttail(1);
    a.inserttail(2);
    a.inserttail(3);
    b.inserttail(4);
    b.inserttail(5);
    a.merge(a, b);
    a.show();
}
