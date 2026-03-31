#include<iostream>
using namespace std;
template <class elemtype>
class queue
{
private:
    elemtype *p;
    int maxsize;
    int front;
    int rear;
    void doublespace()
    {
        elemtype *tem=p;
        p=new elemtype[2*maxsize];
        for (int i=1;i<=maxsize;i++)
        {
            p[i]=tem[(front+i)%maxsize];

        }
        front=0;
        rear=maxsize;
        maxsize*=2;
        delete []tem;

    }
public:
    queue()
    {
        front=rear=0;
        maxsize=10;
        p=new elemtype[maxsize];

    }
    ~queue()
    {
        delete []p;
        p=nullptr;

    }
    bool isEmpty()
    {
        return (front==rear);
    }
    void enqueue(const elemtype &x)
    {
        if ((rear+1)%maxsize==front)
        {
            doublespace();

        }
        rear=(rear+1)%maxsize;
        p[rear]=x;
    }
    elemtype dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        front=(front+1)%maxsize;
        return p[front];



    }
    elemtype gethead()
    {
        return p[(front+1)%maxsize];

    }

};

template <class elemtype>
class linkqueue
{
private:
    struct Node
    {
        elemtype data;
        Node *next;
        Node(elemtype data_=0)
        {
            data=data_;

            next=nullptr;
        }

    };
    Node *front;
    Node *rear;
public:
    linkqueue()
    {
        front=new Node();
        rear=front;

    }
    ~linkqueue()
    {
        Node *p=front->next;
        while (p!=nullptr)
        {
            delete front;
            front=front->next;
            p=p->next;

        }
    }
    bool isEmpty()
    {
        return (front==rear);
    }
    void enqueue(const elemtype &x)
    {
        if (isEmpty())
        {
            front=rear=new Node(x);
            return;
        }
        Node *tem=new Node(x);
        rear->next=tem;
        rear=tem;
    }
    elemtype dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        elemtype val =front->data;
        front=front->next;
        if (front==nullptr)
        {
            rear=nullptr;
        }
        return val;
    }
    elemtype gethead()
    {
        if (isEmpty())
        {
            return -1;
        }
        elemtype val=front->data;
        return val;
    }


};

