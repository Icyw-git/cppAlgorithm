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

    elemtype getlast()
    {
        if (isEmpty())
        {
            return -1;
        }
        elemtype val=rear->data;
        return val;
    }


};

//火车车厢重排问题：车站中有一条入轨，一条出轨，k条侧轨，火车车厢按顺序入轨，要求将车厢按指定顺序出轨，问是否可行。侧轨只能用来暂时停放车厢，不能改变车厢的顺序。侧轨的数量k是有限的。
//当车厢的初始序列为3，6，9，2，4，7，1，8，5，目标序列为1，2，3，4，5，6，7，8，9时，如果k=2，则无法完成重排；如果k=3，则可以完成重排。请设计一个算法来判断给定的初始序列、目标序列和侧轨数量k是否能够完成重排。

//函数设计：
bool putBuffer(linkqueue<int> *buffer,int k,int in ); //将车厢in放入侧轨buffer中，返回是否成功放入
void checkBuffer(linkqueue<int> *buffer,int k,int &last); //检查侧轨buffer中是否有车厢可以出轨，如果有则出轨，并更新last为最后一个出轨的车厢编号

void arrange(int in[],int n,int k)
{
    linkqueue <int> *buffer=new linkqueue<int> [k]; //创建k条侧轨，每条侧轨用一个链接队列来实现
    int last=0;
    for (int i=0;i<n;i++)
    {
        if (!putBuffer(buffer,k,in[i])) //如果无法将车厢in[i]放入侧轨buffer中 说明无法完成重排 直接返回
        {
            return ;
        }
        checkBuffer(buffer,k,last);
    }
}

bool putBuffer(linkqueue<int> *buffer,int k,int in)
{
    int avail=-1;
    int max=0;
    for (int i=0;i<k;i++)
    {
        if (buffer[k].isEmpty())
        {
            avail=k;
        }
        if (buffer[k].getlast()<in &&buffer[k].getlast()>max )
        {
            avail=k;
            max=buffer[k].getlast();
        }


    }

    if (avail!=-1)
    {
        cout<<in<<"进入缓冲区"<<avail<<endl;
        return true;


    }
    else
    {
        cout<<in<<"无法进入缓冲区"<<endl;
        return false;
    }
}

void checkBuffer(linkqueue<int> *buffer,int k,int &last)
{
    int flag=true;
    while (flag)
    {
        flag=false;
        for (int j=0;j<k;j++)
        {
            if (buffer[k].gethead()==last+1)
            {
                cout<<buffer[k].dequeue()<<"出缓冲区"<<j<<endl;
                last++;
                flag=true;
                break;

            }
        }
    }
}

