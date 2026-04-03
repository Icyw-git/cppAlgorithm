#include <iostream>
#include <cstring>
#include <vector>  // 可以使用vector简化
using namespace std;

class Array
{
private:
    int *p;         // 指向数组的指针
    int capacity;   // 数组的容量
    int size;       // 数组的当前元素个数

public:
    Array(int initial_capacity = 10);
    Array(const Array& other);  // 拷贝构造函数
    ~Array();
    Array& operator=(const Array& other);  // 赋值运算符

    void show() const;
    static Array symmetricDifference(const Array &a, const Array &b);
    void inserttail(int val);
    int getSize() const { return size; }
    int at(int index) const;  // 获取指定位置的元素

private:
    void expand(int new_capacity);
};

// 构造函数
Array::Array(int initial_capacity)
{
    capacity = initial_capacity;
    p = new int[capacity];
    size = 0;
}

// 拷贝构造函数
Array::Array(const Array& other)
{
    capacity = other.capacity;
    size = other.size;
    p = new int[capacity];
    memcpy(p, other.p, size * sizeof(int));
}

// 赋值运算符
Array& Array::operator=(const Array& other)
{
    if (this != &other) {
        delete[] p;
        capacity = other.capacity;
        size = other.size;
        p = new int[capacity];
        memcpy(p, other.p, size * sizeof(int));
    }
    return *this;
}

// 析构函数
Array::~Array()
{
    delete[] p;
    p = nullptr;
}

// 扩容函数
void Array::expand(int new_capacity)
{
    int *q = new int[new_capacity];
    memcpy(q, p, size * sizeof(int));
    delete[] p;
    p = q;
    capacity = new_capacity;
}

// 在末尾插入元素
void Array::inserttail(int val)
{
    if (size >= capacity) {
        expand(capacity * 2);
    }
    p[size++] = val;
}

// 获取指定位置的元素
int Array::at(int index) const
{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return p[index];
}

// 显示数组内容
void Array::show() const
{
    if (size == 0) {
        cout << "Empty";
    } else {
        for (int i = 0; i < size; i++) {
            if (i > 0) cout << " ";
            cout << p[i];
        }
    }
    cout << endl;
}

// 计算对称差集的核心函数
Array Array::symmetricDifference(const Array &a, const Array &b)
{
    Array result;
    int i = 0, j = 0;
    int n = a.getSize(), m = b.getSize();

    while (i < n && j < m) {
        int val_a = a.at(i);
        int val_b = b.at(j);

        if (val_a < val_b) {
            // 只出现在A中
            result.inserttail(val_a);
            // 跳过A中所有相同的val_a
            while (i < n && a.at(i) == val_a) i++;
        }
        else if (val_a > val_b) {
            // 只出现在B中
            result.inserttail(val_b);
            // 跳过B中所有相同的val_b
            while (j < m && b.at(j) == val_b) j++;
        }
        else {
            // 在A和B中都出现，跳过
            int val = val_a;
            while (i < n && a.at(i) == val) i++;
            while (j < m && b.at(j) == val) j++;
        }
    }

    // 处理A的剩余部分
    while (i < n) {
        int val = a.at(i);
        result.inserttail(val);
        while (i < n && a.at(i) == val) i++;
    }

    // 处理B的剩余部分
    while (j < m) {
        int val = b.at(j);
        result.inserttail(val);
        while (j < m && b.at(j) == val) j++;
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    Array a, b;

    // 读取数组A
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a.inserttail(val);
    }

    // 读取数组B
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        b.inserttail(val);
    }

    Array c = Array::symmetricDifference(a, b);
    c.show();

    return 0;
}
