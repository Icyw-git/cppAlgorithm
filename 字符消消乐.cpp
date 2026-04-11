//
// Created by icyw on 2026/4/10.
//
#include <iostream>
#include <string>
using namespace std;

template <class elemType>
class stack
{
public:
    virtual void push(elemType val) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() = 0;
    virtual bool empty() = 0;

    virtual ~stack()
    {
    }
};

template <class elemType>
class seqstack : public stack<elemType>
{
private:
    elemType *data;
    int top_p;
    int maxsize;

    void doublespace()
    {
        elemType *tem = data;
        data = new elemType[2 * maxsize];
        for (int i = 0; i < maxsize; i++)
        {
            data[i] = tem[i];
        }
        maxsize *= 2;
        delete[] tem;
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
        delete[] data;
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

void erase(string s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        seqstack<char> st;
        for (char c : s[i])
        {
            if (st.empty() || st.top() != c) //如果栈为空或者栈顶元素和当前字符不相等,说明当前字符不能和栈顶元素消除,需要入栈
            {
                st.push(c);
            }
            else
            {
                st.pop();
            }
        }
        string result = "";
        if (st.empty())
        {
            cout << result << endl;
        }
        else
        {

            while (!st.empty())
            {
                result = st.top() + result;
                st.pop();
            }
            cout << result << endl;
        }
    }
}

void erase1(string s)
{
    seqstack<char> st;
    for (char c : s)
    {
        if (st.empty() || st.top() != c)
        {
            st.push(c);
        }
        else
        {
            st.pop();
        }
    }
    string result = "";
    if (st.empty())
    {
        cout << result << endl;
    }
    else
    {

        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        cout << result << endl;
    }
}

int main()
{

    string s;
    cin >> s;
    erase1(s);
}