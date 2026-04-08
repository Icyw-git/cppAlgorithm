#include<iostream>
using namespace std;
template<class elemtype>
class queue
{
    elemtype *p;
    int maxsize;
    int front ;
    int rear;
    int currentsize;
    void doublespace()
    {
        elemtype *tem=p;
        p=new elemtype[2*maxsize];
        for (int i=1;i<=maxsize;i++)
        {
            p[i]=tem[(front+1)%maxsize];

        }
        front =0;
        rear=maxsize;
        maxsize*=2;
        delete []tem;

    }
public:
    queue(int size=10)
    {
        front=rear=0;
        maxsize=size;
        currentsize=0;
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

    bool isFull()
    {
        return (rear+1)%maxsize==front;
    }
    void enqueue(const elemtype &x)
    {
        if ((rear+1)%maxsize==front) //rear紧挨着front说明队列满了 需要扩容
        {
            doublespace();

        }
        rear=(rear+1)%maxsize;
        p[rear]=x;
        currentsize++;
    }
    elemtype dequeue()
    {
        if (isEmpty())
        {
            return -1; //空队列不能执行出队操作 返回-1表示出队失败
        }
        front=(front+1)%maxsize;
        currentsize--;
        return p[front];



    }
    elemtype gethead()
    {
        return p[(front+1)%maxsize];

    }

    int getsize()
    {
        return currentsize;
    }


};

void api(int id,char c,int n,int a[])
{
    queue<int> b(10);
    int maxsize;
    if (c=='a')
    {
        maxsize=3;
    }
    if (c=='b')
    {
        maxsize=6;
    }
    if (c=='c')
    {
        maxsize=9;
    }

    int target=id;
    for (int i=0;i<n;i++)
    {
        if (b.gethead()<i-9 && !b.isEmpty()) //如果队头元素小于i-9说明队头元素已经不在窗口内了 需要出队
        {
            b.dequeue();
        }
        if (a[i]!=target) //如果当前元素不等于目标值 说明不需要入队 直接输出0
        {
            cout<<0<<' ';
        }
        else
        {
            if (b.getsize()<maxsize) //如果当前窗口内的元素个数小于最大窗口大小 说明可以入队
            {
                b.enqueue(i);
                cout<<1<<' ';
            }
            else
            {
                cout<<-1<<' ';
            }
        }
    }

}



int main()
{
    int id;
    cin>>id;
    char c;
    cin>>c;
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    api(id,c,n,a);

}