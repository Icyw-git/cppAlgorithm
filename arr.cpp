#include <iostream>
#include <cstring>
using namespace std;

class Array
{
private:
    int* p; // 指向数组的指针
    int capacity; // 数组的容积
    int size; // 数组的元素个数
public:
    Array(int size = 10); // 构造函数
    ~Array(); // 析构函数
    void push_back(int x); // 末尾增加元素
    void pop_back(); // 末尾删除元素
    void insert(int loc, int x); // 按位置插入元素
    void erase(int val); // 按值删除元素
    int find(int x); // 查找元素
    void show();

private:
    void expand(int new_capacity) // 自动扩容函数
    {
        int* q;
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
        cout << p[i] << endl;
    }
}

void reverse(int* arr, int size)
{
    int* p = arr;
    int* q = arr + size - 1; // 双指针，将偶数移至左侧，奇数移至右侧

    while (p < q)
    {
        while (p < q)
        {
            if (*p % 2 == 1) // 遇到奇数
            {
                break;
            }
            p++;
        }
        while (p < q)
        {
            if (*q % 2 == 0) // 遇到偶数
            {
                break;
            }
            q--;
        }
        if (p < q) // 指针交换
        {
            int temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }
}

int count(int* arr, int size, int val) // 删除数组中值等于val的数，并计数
{
    int* p = arr;
    int* q = arr; // 快指针，检测数值
    while (q <= arr + size - 1)
    {
        if (*q == val)
        {
            q++;
            continue;
        }
        else
        {
            *p = *q; // 将不等于val的数移至数组前方

            p++;
            q++; // 更新指针
        }
    }
    return p - arr;
}

int main()
{
    // Array a(5);
    // a.push_back(2);
    // a.push_back(3);
    // int b=a.find(2);
    // cout<<b<<endl;
    // a.insert(1,4);
    // a.show();

    int c[6] = {1, 2, 2, 4, 5, 6};
    reverse(c, 6);
    for (int i : c)
    {
        cout << i << endl;
    }
    cout << count(c, 6, 2);
}
