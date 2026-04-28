//
// Created by icyw on 2026/4/28.
//

#include<iostream>
using namespace std;


//最小化堆

class priorityqueue
{
    private:
    int currentSize;
    int *array;
    int maxSize;

    void doublespace()
    {
        int *tem=array;
        array=new int[2*maxSize];
        for (int i=0;i<maxSize;i++)
        {
            array[i]=tem[i];
        }
        maxSize*=2;
        delete []tem;
    }

    void buildHeap()
    {
        for (int i=currentSize/2;i>0;i--)
        {
            percolateDown(i);
        }
    }

    void percolateDown(int hole)
    {
        int child;
        int temp=array[hole];
        for (;hole*2<=currentSize;hole=child)
        {
            child=hole*2;
            if (child!=currentSize&&array[child]>array[child+1])
            {
                child++;
            }
            if (temp>array[child])
            {
                array[hole]=array[child];
            }
            else
            {
                break;
            }

        }
            array[hole]=temp;

    }

public:
    priorityqueue(int capacity=10)
    {
        array=new int[capacity];
        maxSize=capacity;
        currentSize=0;

    }
    ~priorityqueue()
    {
        delete []array;
    }
    bool isEmpty()
    {
        return currentSize==0;
    }

    int getHead()
    {
        return array[1];
    }

    void enqueue(int x)
    {
        if (currentSize==maxSize-1)
        {
            doublespace();
        }
        int hole=currentSize+1;
        for (;hole>1&&x<array[hole/2];hole/=2)
        {            array[hole]=array[hole/2];
        }
        array[hole]=x;
        currentSize++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        int temp=array[1];
        array[1]=array[currentSize];
        currentSize--;
        percolateDown(1);
        return temp;
    }


};