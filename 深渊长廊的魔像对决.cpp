#include<iostream>
using namespace std;

class stack
{
private:
    int* data;
    int top_p;
    int maxsize;

    void doublespace()
    {
        int* tem = data;
        data = new int[2 * maxsize];
        for (int i = 0; i < maxsize; i++)
        {
            data[i] = tem[i];
        }
        maxsize *= 2;
        delete []tem;
    }

public:
    stack(int size)
    {
        data = new int[size];
        top_p = -1;
        maxsize = size;
    }

    ~stack()
    {
        delete []data;
    }

    void push(int x)
    {
        if (top_p == maxsize - 1)
        {
            doublespace();
        }
        top_p = top_p + 1;
        data[top_p] = x;
    }

    int pop()
    {
        if (top_p == -1)
        {
            return -1;
        }
        int tem = data[top_p];
        top_p--;
        return tem;
    }

    int top()
    {
        if (top_p == -1)
        {
            return -1;
        }
        return data[top_p];
    }

    bool isEmpty()
    {
        return top_p == -1;
    }
};

void crash(int a[], int n)
{
    stack s(n);
    int i = 0;
    while (i < n)
    {
        if (s.isEmpty() || s.top() * a[i] > 0 || (s.top() < 0 && a[i] > 0))
        {
            s.push(a[i]);
            i++;
        }
        else
        {
            if (s.top() > abs(a[i]))
            {
                i++;
            }
            else if (s.top() < abs(a[i]))
            {
                s.pop();
                s.push(a[i]);
                i++;
            }
            else
            {
                s.pop();
                i++;
            }
        }
    }
    if (s.isEmpty())
    {
        cout << "EMPTY" << endl;
    }
    else
    {
        stack tem(n);
        while (!s.isEmpty())
        {
            tem.push(s.pop());
        }
        while (!tem.isEmpty())
        {
            cout << tem.pop() << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    crash(a, n);
    return 0;
}
