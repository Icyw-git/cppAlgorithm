//
// Created by icyw on 2026/4/29.
//

#include<iostream>
using namespace std;

//实现最小化堆
class minheap
{
private:
    int maxsize;
    int *array;
    int currentsize;

    void doublespace()
    {
        int *temp=array;
        array=new int [2*maxsize];
        for (int i=0;i<maxsize;i++)
        {
            array[i]=temp[i];
        }

        maxsize=2*maxsize;
        delete []temp;

    }

    void percolate(int hole)
    {
        int child=hole*2;
            int temp=array[hole];


        for (;hole*2<=currentsize;hole=child)
        {
            if (child!=currentsize&& array[child]>array[child+1] )
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
    minheap(int size=100)
    {
        array=new int [size+1];
        maxsize=size+1;
        currentsize=0;

    }

    ~minheap()
    {
        delete[] array;
    }

    bool isempty()
    {
        return currentsize==0;


    }

    int gethead()
    {
        return array[1];
    }

    void enqueue(int element)

    {
        if (currentsize==maxsize-1)
        {
            doublespace();
        }

        int hole=currentsize+1;
        for (;hole>1 &&element<array[hole/2];hole/=2)
        {
            array[hole]=array[hole/2];

        }
        array[hole]=element;
        currentsize++;

    }

    void dequeue()
    {
        if (isempty())
        {
            return ;

        }
        int val=array[1];
        array[1]=array[currentsize];
        currentsize--;
        percolate(1);
        cout<<val<<endl;



    }
};


int main()
{
    int n;
    cin>>n;
    minheap h;
    for (int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        if (k==1)
        {
            int x;
            cin>>x;
            h.enqueue(x);
        }
        if (k==2)
        {
            h.dequeue();

        }
    }
}