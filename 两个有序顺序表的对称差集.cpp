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
    void show();

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

