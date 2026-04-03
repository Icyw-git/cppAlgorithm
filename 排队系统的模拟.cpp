#include<iostream>
using namespace std;

template <class elemtype>
class linkqueue //链接队列的实现
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
        front=front->next; //移动front指针至下一个节点
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

    elemtype gettail()
    {
        if (isEmpty())
        {
            return -1;

        }
        elemtype val=rear->data;
        return val;

    }


};