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
        p=new int [2*maxsize];
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
    ~stack();
    void pop();
    void top();

};