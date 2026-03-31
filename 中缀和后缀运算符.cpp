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

void print(int num)
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

void transfer(char a[],int n)
{
    stack<int> b(n);
    stack<char> c(n);
    for (int i=0;i<n;i++)
    {
        if (isdigit(a[i]))
        {
            b.push(a[i]);
        }
        else if (a[i]=='(')
        {
            c.push(a[i]);
        }
        else if (a[i]==')')
        {
            while (b.top()!='(')
            {
                cout<<b.pop()<<' ';
            }
            cout<<b.pop()<<' ';
        }
        else if (a[i]=='*'){}
    }
}

int main()
{
    print(123456778);

}