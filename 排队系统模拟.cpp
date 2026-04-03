#include<iostream>
#include<ctime>

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
        Node *current=front;
        while (front!=nullptr)
        {
            Node *next=front->next;
            delete current;
            current=next;
        }
    }
    bool isEmpty()
    {
        return (front==nullptr);
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

//单服务台的排队系统实现
double simulate(int n)
{

    double totalwaittime=0;
    double currenttime=0;

    linkqueue <double> t;
    for (int i=0;i<n;i++)
    {
        double time=rand()%30;
        currenttime+=time;

        cout<<"生成到达时间为"<<currenttime<<"分钟"<<"的顾客"<<endl;
        t.enqueue(currenttime);




    }

    currenttime=0;
    while (!t.isEmpty())
    {
        double arrivetime=t.dequeue();
        if (arrivetime>currenttime)
        {
            currenttime=arrivetime;
            double servicetime=rand()%30;
            cout<<"无需等待，服务时间为"<<servicetime<<"分钟"<<endl;
            currenttime+=servicetime;
        }
        else
        {
            double waittime=currenttime-arrivetime;
            double servicetime=rand()%30;
            cout<<"需要等待"<<waittime<<"分钟，服务时间为"<<servicetime<<"分钟"<<endl;
            currenttime+=servicetime;
            totalwaittime+=waittime;
        }
    }
    return totalwaittime/n;

}

int main()
{
    srand(time(0));

    int n;
    cin>>n;
    cout<<simulate(n)<<endl;
}