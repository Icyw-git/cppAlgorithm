#include<iostream>
using namespace std;

template<class elemType>
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

void getmax(int a[],int n)
{
    seqstack<int> b(n);
    int c[n];
    for (int i=n-1;i>=0;i--) //从右向左遍历数组，维护一个单调递减的栈，当前元素的可能的右侧第一个最大值就是栈顶元素，如果当前元素大于等于栈顶元素，则弹出栈顶元素，直到找到一个比当前元素大的元素或者栈为空，因为这些元素是不可能成为当前元素以及后续元素的右侧第一个最大值的，所以需要弹出，最后如果栈不为空，则当前元素的右侧第一个最大值就是栈顶元素，否则当前元素没有右侧第一个最大值。每次遍历完当前元素后，将当前元素入栈，继续遍历下一个元素。
    {
        while (!b.empty()&&a[i]>=a[b.top()])
        {
            b.pop();

        }
        if (!b.empty())
        {
            c[i]=b.top()+1;

        }else
        {
            c[i]=0;

        }

        b.push(i);
    }
    for (int i=0;i<n;i++)
    {
        cout<<c[i]<<' ';
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    getmax(a,n);
}