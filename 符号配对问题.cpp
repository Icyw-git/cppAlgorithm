#include<iostream>
using namespace std;

//定义栈
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


bool Ispaired(char c[],int n)
{
    seqstack<char> s;
    for (int i=0;i<n;i++)
    {
        switch (c[i]){
        case '[':
        case '{':
        case'(': s.push(c[i]);
            break;
        case ']': if (s.empty() || s.pop() != '[') //当遇到右括号时，首先检查栈是否为空，如果为空则说明没有与之匹配的左括号，返回false；如果不为空，则弹出栈顶元素并检查是否与当前右括号匹配，如果不匹配则说明括号不配对，
            return false;
            break;
        case'}':if (s.empty() || s.pop() != '{')
            return false;
            break;
        case ')':if (s.empty() || s.pop() != '(')
            return false;
            break;
        }
    }
    return s.empty();
}

int main()
{
    int n;
    cin>>n;
    char c[n];
    for (int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    cout<<Ispaired(c,n)<<endl;
     return 0;
}