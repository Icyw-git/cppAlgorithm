#include<iostream>
using namespace std;
template <class elemtype>

class linklist
{
    struct Node
    {
        elemtype data;
        Node *next;
        Node(elemtype d=0)
        {
            data=d;
            next=nullptr;
        }


    };
    Node *head;
    int length=0;
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
        while (p !=nullptr)
        {
            delete q;
            q=p;
            p=p->next;
        }
        length=0;
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

    void show()
    {
        Node *p=head;
        cout<<p->data<<' ';
        while (p->next !=nullptr)
        {
            p=p->next;
            cout<<p->data<<' ';
        }
        cout<<endl;
    }

    void circle()
    {
        Node *p=head;
        while (p->next !=nullptr)
        {
            p=p->next;
        }
        p->next=head;
        Node *q=head;

        while (q !=q->next)
        {
            p=q->next;
            q=p->next;
            p->next=q->next;
            cout<<q->data<<' ';
            delete q;
            q=p->next;

        }
        cout<<endl;

        cout<<q->data<<endl;


    }



};

int main()
{
    linklist<int> l;
    l.inserttail(1);
    l.inserttail(2);
    l.inserttail(3);
    l.inserttail(4);

    l.show();
    l.circle();


}