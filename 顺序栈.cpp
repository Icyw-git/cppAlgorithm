//
// Created by icyw on 2026/3/17.
//

#include<iostream>
using namespace std;
class stack
{
private:
    int *p;
    int maxsize;
    int top_p;
    void doublespace()
    {
        int *tem=p;
        maxsize*=2;

        p=new int [maxsize];

        for(int i=0;i<maxsize;i++)
        {
            p[i]=tem[i];

        }
        delete []tem;

    }
public:
    stack(int size)
    {
        maxsize = size;
        p=new int[maxsize];
        top_p=-1;

    }
    ~stack()
    {
        delete []p;
        p=nullptr;
    }
    void pop();
    void top();
    void push(int val);
    bool isempty();



};

void stack::push(int val)
{
    if (top_p==maxsize-1)
    {
        doublespace();

    }
    top_p++;
    p[top_p]=val;

}

void stack::pop()
{
    int val=p[top_p];
    top_p--;
    cout<<val<<endl;

}

void stack::top()
{
    cout<<p[top_p]<<endl;
}

int main()
{
    stack a(10);
    for (int i=0;i<10;i++)
    {
        a.push(i);
    }
    a.pop();
    a.top();


}