#include<iostream>
using namespace std;
template <class elemtype>
class queue//循环队列的实现
{
private:
    elemtype *p;
    int maxsize;
    int front; //指向队头元素的前一个位置
    int rear;// 指向队尾的元素
    void doublespace()
    {
        elemtype *tem=p;
        p=new elemtype[2*maxsize];
        for (int i=1;i<=maxsize;i++) //因为front指向的是队头的前一个元素 所以i从一开始
        {
            p[i]=tem[(front+i)%maxsize]; //循环队列取模运算

        }
        front=0; //指向队头的前一个位置
        rear=maxsize; //指向队尾
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
        if ((rear+1)%maxsize==front) //rear紧挨着front说明队列满了 需要扩容
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
            return -1; //空队列不能执行出队操作 返回-1表示出队失败
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


};

