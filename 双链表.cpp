//
// Created by icyw on 2026/3/17.
//
#include<iostream>
using namespace std;

class List
{
private:
    struct Node
    {
        int data;
        Node* prev;
        Node* next;

        Node(int data_ = 0, Node* p = nullptr, Node* n = nullptr)
        {
            data = data_;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;
    int length;

public:
    List()
    {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
        length = 0;
    }

    ~List()
    {
        Node* p = head->next;
        Node* q = head;
        head->next = nullptr;
        while (p != nullptr)
        {
            delete q;
            q = p;
            p = p->next;
        }
    }

    void insert(int i, int data);
    void remove(int i);
    void show();
    int visit(int i);
    int serach(int val);
};

void List::insert(int i, int data)
{
    Node* p = head->next;
    while (i > 0)
    {
        p = p->next;
        i--;
    }
    Node* tem = new Node(data, p->prev, p);
    p->prev->next = tem;
    p->prev = tem;
    length++;
}

void List::remove(int i)
{
    Node* p = head->next;
    while (i > 0)
    {
        p = p->next;
        i--;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    length--;
}

void List::show()
{
    Node* p = head->next;
    while (p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    List l1;
    l1.insert(0, 1);
    l1.insert(0, 2);
    l1.insert(0, 3);
    l1.show();
}
