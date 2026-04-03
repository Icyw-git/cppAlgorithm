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

