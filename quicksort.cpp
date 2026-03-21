//快速排序的递归实现
#include<iostream>
using namespace std;
int divide(int arr[],int left,int right,int &pivot);

void quicksort(int arr[],int left,int right)
{
    int pivot=arr[left];
    if (left>=right)
    {
        return;
    } //注意设置停止条件,当left>=right时,表示数组已经排序完成,返回

    int mid=divide(arr,left,right,pivot);
    quicksort(arr,left,mid-1);
    quicksort(arr,mid+1,right);


}

int divide(int arr[],int left,int right,int &pivot) //将比pivot小的数放在左边,比pivot大的数放在右边,返回pivot的最终位置
{
    int i=left;
    int j=right;
    pivot=arr[left];
    while (i<j)
    {
        while (i<j && arr[j]>=pivot) j--; //跳过比pivot大的数
        if (i<j) arr[i++]=arr[j]; //将比pivot大的数放在左边
        while (i<j && arr[i]<=pivot) i++;
        if (i<j) arr[j--]=arr[i];
    }
    arr[i]=pivot;
    return i;
}



//非递归实现
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

void quicksort1(int arr[],int left,int right)
{
   seqstack<int> sl;
    seqstack<int> sr;
    sl.push(left); //存储待排序数组的左边界
    sr.push(right); //存储待排序数组的右边界
    while (!sl.empty() && !sr.empty()) //栈为空为终止条件
    {
        left=sl.pop();
        right=sr.pop();
        if (left>=right) //当left>=right时,表示数组已经排序完成,继续下一轮循环
        {
            continue;

        }
        int pivot=arr[left];
        int mid=divide(arr,left,right,pivot);
        if (right-mid-1>0) //为多个元素的时候才入栈
        {
            sl.push(mid+1);
            sr.push(right);
        }
        if (mid-1-left>0) //为多个元素的时候才入栈
        {
            sl.push(left);
            sr.push(mid-1);
        }

    }

}


int divide1(int arr[],int left,int right);

void quickersort(int arr[],int left,int right)
{
    if (left>=right)
    {
        return;
    }
    int mid=divide1(arr,left,right);
    quickersort(arr,left,mid-1);
    quickersort(arr,mid+1,right);

}

int divide1(int arr[],int left,int right) //挖坑填数法
{
    int pivot=arr[left];
    while (left<right)
    {
        while (left <right &&arr[right]>=pivot)
        {
            right--;
        }
        if (left<right)
        {
            arr[left]=arr[right];
            left++;

        }

        while (left<right &&arr[left]<=pivot)
        {
            left++;
        }
        if (left<right)
        {
            arr[right]=arr[left];
            right--;
        }
    }
    arr[left]=pivot;
    return left;

}

void quicksort2(int arr[],int left,int right)
{
    seqstack<int> sl;
    seqstack<int> sr;
    sl.push(left);
    sr.push(right);
    while (!sl.empty() &&!sr.empty())
    {
        left=sl.pop();
        right=sr.pop();
        if (left>=right)
        {
            continue;
        }
        int mid=divide1(arr,left,right);
        if (right-mid-1>0)
        {
            sr.push(right);
            sl.push(mid+1);

        }
        if (mid-1-left>0)
        {
            sr.push(mid-1);
            sl.push(left);

        }
    }

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quicksort2(arr,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;







}