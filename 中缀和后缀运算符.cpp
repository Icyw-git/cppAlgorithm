#include<iostream>
using namespace std;

template<class elemtype>
class stack{
private:
    elemtype *p;
    int maxsize;
    int top_p;
    void doublespace()
    {
        elemtype *tem=p;
        p=new elemtype[maxsize*2];
        for (int i=0;i<maxsize;i++)
        {
            p[i]=tem[i];
        }
        maxsize*=2;
        delete  []tem;

    }
public:
    stack(int size)
    {
        maxsize=size;

        p=new elemtype[maxsize];
        top_p=-1;

    }

    ~stack()
    {
        delete []p;
        p=nullptr;

    }
    void push(elemtype val)
    {
        p[top_p+1]=val;
        top_p+=1;
    }

    elemtype pop()
    {
        elemtype tem=p[top_p];
        top_p--;
        return tem;
    }

    elemtype top()
    {
        return p[top_p];

    }
    bool isEmpty()
    {
        return (top_p==-1);

    }
};

void print(int num) //利用栈的性质消除递归

{
    stack<int> a(10);
    while (num !=0)
    {
        a.push(num%10);
        num/=10;
    }
    while (!a.isEmpty())
    {
        cout<<a.pop()<<' ';
    }

}

bool isoperator(char c)
{
    return c=='+'||c=='-'||c=='*'||c=='/';
}

void transfer(char a[],int n)
{
    stack<char> c(n);
    for (int i=0;i<n;i++)
    {
        if (isdigit(a[i]))
        {
            cout<<a[i]<<" ";
        }
        else if (a[i]=='(')
        {
            c.push(a[i]);
        }
        else if (a[i]==')')
        {
            while (c.top()!='(' && !c.isEmpty())
            {
                cout<<c.pop()<<' ';
            }
            cout<<c.pop()<<' ';
        }
        else if (isoperator(a[i]))
        {
            while ()
        }
    }
}

int main()
{
    print(123456778);

}