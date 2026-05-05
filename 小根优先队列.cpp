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

    void percolate(int hole) //下漏，给定hole挖掉该位置的元素，向下调整堆以保持最小堆性质
    {
        int child=hole*2; //获取hole节点的左孩子
            int temp=array[hole];


        for (;hole*2<=currentsize;hole=child) //保证左孩子位于堆内，每次循环末尾hole更新为child继续向下调整
        {
            if (child!=currentsize&& array[child]>array[child+1] ) //如果右孩子存在且比左孩子小，则child赋值为右孩子索引
            {
                child++;
            }
            if (temp>array[child]) //如果child位置较小，则将child位置的元素上移到hole位置，继续向下调整
            {
                array[hole]=array[child];
            }
            else
            {
                break;
            }


        }
        array[hole]=temp; //最后将最初挖掉的元素放到最终的hole位置，完成下漏调整

    }

public:
    minheap(int size=100)
    {
        array=new int [size+1];  //数组索引从1开始使用
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

        int hole=currentsize+1; //添加至数组末尾
        for (;hole>1 &&element<array[hole/2];hole/=2) //如果新元素比父节点小，则将父节点上移到hole位置，继续向上调整
        {
            array[hole]=array[hole/2];  //hole上移，hole更新为父节点索引继续比较

        }
        array[hole]=element; //最后将新元素赋值在hole位置，完成上浮调整
        currentsize++;

    }

    void dequeue()
    {
        if (isempty())
        {
            return ;

        }
        int val=array[1];
        array[1]=array[currentsize]; //将最后一个元素放在队首，然后下漏
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