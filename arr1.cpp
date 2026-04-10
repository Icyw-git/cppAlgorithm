//
// Created by icyw on 2026/3/4.
//
#include<iostream>
#include <list>
using namespace std;

template <class elemType>
class list
{
public:
    virtual void clear() =0;
    virtual int length() const =0;
    virtual void insert(int i, const elemType& x) =0;
    virtual void remove(int i) =0;
    virtual int search(const elemType& x) const =0;
    virtual elemType visit(int i) const =0;
    virtual void traverse() const =0;

    virtual ~list()
    {
    } //
};

template <class elemType>
class seqList : public list<elemType>
{
private:
    elemType* data;
    int currentLength;
    int maxSize;
    void doubleSpace();

public:
    seqList(int initSize = 10)
    {
        data = new elemType[initSize];

        currentLength = 0;
        maxSize = initSize;
    }

    ~seqList()
    {
        delete[] data;
    }

    void clear();
    int length() const;
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType& x);
    elemType visit(int i) const;
    void traverse() const;
    void erase(int i);
    void erase1(int i);
    void erase2(int i);
};

template <class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType* tem = new elemType[2 * maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        tem[i] = data[i];
    }
    data = tem;
    delete []tem;
}

template <class elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

template <class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template <class elemType>
void seqList<elemType>::traverse() const
{
    for (int i = 0; i < currentLength; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

template <class elemType>
int seqList<elemType>::search(const elemType& x)
{
    for (int i = 0; i < currentLength; i++)
    {
        if (data[i] == x)
        {
            return i;
        }
    }
    return -1;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType& x)
{
    for (int j = currentLength - 1; j >= i; j--)
    {
        data[j] = data[j + 1];
    }
    data[i] = x;
}


template <class elemType>
void seqList<elemType>::remove(int i)
{
    for (int j = i + 1; j < currentLength; j++)
    {
        data[j] = data[j - 1];
    }
    currentLength--;
}

template <class elemType>
void seqList<elemType>::erase(int i)
{
    elemType temp = data[i];
    int cnt = 0;
    for (int j = 0; j < currentLength; j++)
    {
        if (data[j] == temp)
        {
            cnt++;
        }
        else
        {
            data[j] = data[j - cnt];
        }
    }
    currentLength -= cnt;
}

template <class elemType>
void seqList<elemType>::erase1(int i)
{
    elemType* p = data;
    elemType* q = data + currentLength - 1;
    elemType temp = data[i];


    while (p < q)
    {
        if (*q == temp)
        {
            q--;
            continue;
        }
        if (*p == temp)
        {
            *p = *q;
            p++;
            q--;
        }
        else
        {
            p++;
        }
    }
}

template <class elemType>
void seqList<elemType>::erase2(int i)
{
    elemType* p = data;
    elemType* q = data;
    elemType temp = data[i];
    while (q <= data + currentLength - 1)
    {
        if (*q == temp)
        {
            q++;
            continue;
        }
        if (*p == temp)
        {
            *p = *q;
            p++;
            q--;
        }
        else
        {
            p++;
        }
    }
}


int main()
{
    seqList<int> a(10);
    a.insert(0, 1);
}
