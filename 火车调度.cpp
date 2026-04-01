#include<iostream>
using namespace std;
template <class elemType>
class stack
{
public:
    virtual void push(elemType val)=0;
    virtual elemType pop()=0;
    virtual elemType top()=0;
    virtual bool empty()=0;
    virtual ~stack() {}


};

template <class elemType>
class seqstack:public stack<elemType>
{
private:
    elemType *data;
    elemType top_p;
    int maxsize;
    void doublespace()
    {
        elemType *tem=data;
        data=new elemType[2*maxsize];
        for (int i=0;i<maxsize;i++)
        {
            data[i]=tem[i];

        }
        maxsize*=2;
        delete []tem;

    }
public:
    seqstack(int initsize=10)
    {
        maxsize=initsize;
        data=new elemType[maxsize];
        top_p=-1;

    }
    void push(elemType val);
    elemType pop();
    elemType top();
    bool empty();
    ~seqstack()
    {
        delete []data;
        data=nullptr;

    }
};

template <class elemType>
void seqstack<elemType>::push(elemType val)
{
    if (top_p==maxsize-1)
    {
        doublespace();
    }
    top_p++;
    data[top_p]=val;
}

template <class elemType>
elemType seqstack<elemType>::pop()
{
    elemType val=data[top_p];
    top_p--;
    return val;
}

template <class elemType>
elemType seqstack<elemType>::top()
{
    return data[top_p];
}

template <class elemType>
bool seqstack<elemType>::empty()
{
    return (top_p==-1);
}

void train(int n,int a[],int b[])
{
    seqstack <int> c;
    int i=0,j=0;
    while (j<n)
    {
        if (!c.empty() && c.top()==b[j])
        {
            c.pop();
            j++;
        }
        else if (i<n)
        {
            c.push(a[i]);
            i++;

        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    if (c.empty())
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    train(n,a,b);
}