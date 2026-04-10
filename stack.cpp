//
// Created by icyw on 2026/3/17.
//

#include<iostream>
using namespace std;

template <class elemType>
class stack
{
public:
    virtual void push(elemType val) =0;
    virtual elemType pop() =0;
    virtual elemType top() =0;
    virtual bool empty() =0;

    virtual ~stack()
    {
    }
};

template <class elemType>
class seqstack : public stack<elemType>
{
private:
    elemType* data;
    elemType top_p;
    int maxsize;

    void doublespace()
    {
        elemType* tem = data;
        data = new elemType[2 * maxsize];
        for (int i = 0; i < maxsize; i++)
        {
            data[i] = tem[i];
        }
        maxsize *= 2;
        delete []tem;
    }

public:
    seqstack(int initsize = 10)
    {
        maxsize = initsize;
        data = new elemType[maxsize];
        top_p = -1;
    }

    void push(elemType val);
    elemType pop();
    elemType top();
    bool empty();

    ~seqstack()
    {
        delete []data;
        data = nullptr;
    }
};

template <class elemType>
void seqstack<elemType>::push(elemType val)
{
    if (top_p == maxsize - 1)
    {
        doublespace();
    }
    top_p++;
    data[top_p] = val;
}

template <class elemType>
elemType seqstack<elemType>::pop()
{
    elemType val = data[top_p];
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
    return (top_p == -1);
}

int main()
{
    seqstack<char> stack;
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        stack.push(a[i]);
    }

    int i = 0;
    while (!stack.empty())
    {
        if (stack.pop() == a[i])
        {
            i++;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}

template <class elemType>
class linkedstack : public stack<elemType>
{
private:
    struct Node
    {
        elemType data;
        Node* next;

        Node()
        {
            data = 0;
            next = nullptr;
        }
    };

    Node* top_p;

public:
    linkedstack()
    {
        top_p = nullptr;
    }

    ~linkedstack()
    {
        Node* p = top_p;
        while (p != nullptr)
        {
            p = p->next;
            delete top_p;
            top_p = p;
        }
    }

    void push(elemType val)
    {
        elemType* tem = new Node(val);
        tem->next = top_p;
        top_p = tem;
    }

    elemType pop()
    {
        Node* p = top_p->next;
        elemType val = top_p->data;
        delete top_p;
        top_p = p;
        return val;
    }

    elemType top()
    {
        return top_p->data;
    }

    bool empty()
    {
        return (top_p == nullptr);
    }
};
