//
// Created by icyw on 2026/4/10.
//

#include<iostream>
using namespace std;

class stack
{
private:
    int *data;
    int top_p;
    int maxsize;
    void doublespace()
    {
        int *tem=data;
        data=new int[2*maxsize];
        for (int i=0;i<maxsize;i++)
        {
            data[i]=tem[i];

        }
        maxsize*=2;
        delete []tem;

    }
public:
    stack()
    {
        data= new int[10];
        top_p=-1;
        maxsize=10;

    }
    void push(int x)
    {
        if(top_p==maxsize-1)
        {
            doublespace();
        }
        top_p=top_p+1;
        data[top_p]=x;
    }
    int pop()
    {
        if(top_p==-1)
        {
            return -1;
        }
        int tem=data[top_p];
        top_p--;
        return tem;

    }
    int top()
    {
        if(top_p==-1)
        {
            return -1;


        }
        return data[top_p];
    }
    bool isEmpty()
    {
        return top_p==-1;

    }

};

class Minstack
{
private:
    stack data;
    stack min;
public:
    void push(int x);
    int pop();
    int top();
    int getMin();
    bool isEmpty();


};

void Minstack::push(int x)
{
    data.push(x);
    if (min.isEmpty() || x<=min.top())
    {
        min.push(x);

    }
    else
    {
        min.push(min.top());
    }

}

int Minstack::pop()
{
    int tem=data.pop();
    min.pop();
    return tem;
}

int Minstack::top()
{
    return data.top();
}

int Minstack::getMin()
{
    return min.top();
}

bool Minstack::isEmpty()
{
    return data.isEmpty();
}

int main()
{
    int n;
    cin>>n;
    Minstack s;
    for (int i=0;i<n;i++)
    {
        string op;
        cin>>op;

        if (op=="push")
        {
            int x;
            cin>>x;
            s.push(x);

        }
        else if (op=="pop")
        {
           s.pop();
        }
        else if (op=="top")
        {
            cout<<s.top()<<endl;
        }
        else if (op=="getMin")
        {
            cout<<s.getMin()<<endl;
        }

    }
}