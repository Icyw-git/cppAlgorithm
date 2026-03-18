#include<iostream>
using namespace std;
template<class elemtype>
class linklist
{
    struct Node
    {
        elemtype data;
        elemtype *next;
        Node(elemtype data_=0)
        {
            data=data_;
            next=nullptr;
        }
    };
    Node *head;
    int length;
public:
    linklist()
    {
        head=new Node();
        length=0;
    }
    ~linklist()
    {
        Node *p=head->next;
        Node *q=head;
        head->next=nullptr;
        while (q!=nullptr)
        {
            q=p->next;
            delete p;
            p=q;

        }
        length=0;
    }

    void show()
    {
        Node *p=head;
        while (p->next !=nullptr)
        {
            p=p->next;

            cout<<p->data<<' ';
        }
    }

    void inserttail(elemtype val)
    {
        Node *p=head;
        while (p->next !=nullptr)
        {
            p=p->next;
        }
        Node *tem=new Node(val);
        p->next=tem;
        length++;
    }

    void crossfind(const linklist &c1,const linklist &c2)
    {
        int size=0;
        Node *p=c1.head;
        Node *q=c2.head;
        if (c1.length>c2.length)
        {
            size=c1.length-c2.length;
            while (size>0)
            {
                p=p->next;
                size--;
            }
            while (p!=nullptr && q!=nullptr)
            {
                if (p!=q)
                {
                    q=q->next;
                    p=p->next;
                }
                else
                {
                    cout<<p->data<<endl;
                    return;
                }

            }
        }



    }


};

template <class elemtype>
class doublelinklist
{
    struct Node
    {
        elemtype data;
        elemtype *prev;
        elemtype *next;
        Node(elemtype data_=0)
        {
            data=data_;
            prev=nullptr;
            next=nullptr;
        }
    };
    Node *head;
    Node* tail;
    int length=0;
public:
    doublelinklist()
    {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;


    }
    ~doublelinklist()
    {
        Node *p=head->next;
        Node *q=head;
        head->next=nullptr;
        while (p!=nullptr)
        {
            q=p->next;
            delete p;
            p=q;

        }
        delete head;
        length=0;
    }
    void insert(int i,elemtype val)
    {
        Node *p=head;
        while (i>0)
        {
            p=p->next;
            i--;
        }
        Node *q=new Node(val);
        q->next=p;
        p->prev->next=q;
        p->prev=q;
        length++;


    }
};