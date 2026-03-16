// 两个有序顺序表的对称差集:题目描述

// 已知两个顺序表A和B，其中元素均按非递减顺序排列。请建立一个新的顺序表C，存放只出现在A或只出现在B中的元素，即去掉两个顺序表中共同出现的元素后，将其余元素按非递减顺序输出，且每个元素在C中只保留一次。
//
// 具体规则
//
// 若某个元素同时在A和B中出现，则不保留
//
// 若某个元素仅出现在其中一个顺序表中，则在C中保留一次
//
// 即使某个元素在同一个顺序表中出现多次，在C中也只保留一次
//
// 输入格式
//
// 第一行输入两个整数n, m，分别表示顺序表A和B的长度
//
// 第二行输入n个整数，表示顺序表A中的元素
//
// 第三行输入m个整数，表示顺序表B中的元素
//
// 注意：
//
// 保证顺序表A和B中的元素均按非递减顺序排列
//
// 当n=0或m=0时，对应的一行可以为空，也可以省略不写
//
// 输出格式
//
// 输出顺序表C中的所有元素，元素之间用一个空格分隔
//
// 若C为空，则输出"Empty"


#include <iostream>
#include <cstring>
using namespace std;
class Array
{
private:
    int *p;       // 指向数组的指针
    int capacity; // 数组的容积
    int size;     // 数组的元素个数
public:
    Array(int size = 10);        // 构造函数
    ~Array();                    // 析构函数
    void push_back(int x);       // 末尾增加元素
    void pop_back();             // 末尾删除元素
    void insert(int loc, int x); // 按位置插入元素
    void erase(int val);         // 按值删除元素
    int find(int x);             // 查找元素
    void show();
    Array result(const Array &a,const Array &b);

private:
    void expand(int new_capacity) // 自动扩容函数
    {
        int *q;
        q = new int[new_capacity];
        memcpy(q, p, size);
        p = q;
        capacity = new_capacity;
    }
};

Array::Array(int size)
{
    capacity = size;
    p = new int[capacity];
    this->size = 0;
}

Array::~Array()
{
    delete[] p;
    p = nullptr; //
}

void Array::push_back(int x)
{
    if (size == capacity)
    {
        expand(2 * size);
    }
    p[size] = x;
    size += 1;
}

void Array::pop_back()
{
    if (size == 0)
    {
        cout << "Array is empty" << endl;
        return;
    }
    size--;
}

void Array::insert(int loc, int x)
{
    if (size == capacity)
    {
        expand(2 * size);
    }
    for (int i = size - 1; i > loc; i--)
    {
        p[i + 1] = p[i];
    }
    p[loc] = x;
    size++;
}

void Array::erase(int val)
{
    if (size == 0)
    {
        cout << "Array is empty" << endl;
        return;
    }
    for (int i = val; i < size; i++)
    {
        p[i - 1] = p[i];
    }
    size--;
}

int Array::find(int x)
{
    for (int i = 0; i < size; i++)
    {
        if (p[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Array::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << p[i] <<" ";
    }
    // cout<<size<<endl;
}

Array Array::result(const Array &a,const Array &b)
{
    Array c(10);
    int *pa=a.p;
    int *pb=b.p;
    int i=0;
    int j=0;


    while (i<a.size && j<b.size)
    {
        if (pa[i]==pb[j])
        {
            int val=pa[i];
            while (i<a.size && pa[i]==val) i++;
            while (j<b.size && pb[j]==val) j++;

        }
        else if (pa[i]<pb[j])
        {
            int val=pa[i];
            c.push_back(val);
            while (i<a.size && pa[i]==val)
            {
                i++;
            }
        }
        else
        {
            int val=pb[j];
            c.push_back(val);
            while (j<b.size && pb[j]==val)
            {
                j++;
            }
        }


    }

    while (i<a.size)
    {
        int val =pa[i];
        c.push_back(val);
        while (i<a.size && pa[i]==val) i++;
    }
    while (j<b.size)
    {
        int val =pb[j];
        c.push_back(val);
        while (j<b.size && pb[j]==val) j++;
    }
    return c;

}



int main()
{
    int n;
    int m;
    cin>>n>>m;
    Array a(n);
    Array b(m);
    for (int i=0;i<n;i++)
    {   int val;
        cin>>val;
        a.push_back(val);
    }
    for (int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        b.push_back(val);
    }
    // a.show();
    // b.show();

    Array c=a.result(a,b);
    c.show();

}