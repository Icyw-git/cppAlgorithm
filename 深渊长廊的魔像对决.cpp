#include <iostream>
using namespace std;

class stack
{
private:
    int* data;
    int top_p;
    int maxsize;
    int length;

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
        length = 0;
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
        length++;
    }

    int pop()
    {
        if (top_p == -1)
        {
            return 0;
        }
        int tem = data[top_p];
        top_p--;
        length--;
        return tem;
    }

    int top()
    {
        if (top_p == -1)
        {
            return 0;
        }
        return data[top_p];
    }

    bool isEmpty()
    {
        return top_p == -1;
    }

    int getlength()
    {
        return length;
    }

    int get(int index)
    {
        if (index >= 0 && index <= top_p)
        {
            return data[index];
        }
        return 0;
    }
};

void crash(int a[], int n)
{
    stack s(n);

    for (int i = 0; i < n; i++)
    {
        int current = a[i];

        while (true)
        {
            if (s.isEmpty())
            {
                s.push(current);
                break;
            }

            int top = s.top();

            if ((top > 0 && current > 0) ||
                (top < 0 && current < 0) ||
                (top < 0 && current > 0))
            {
                s.push(current);
                break;
            }
            else
            {
                int top_value = top;
                int current_value = -current;

                if (top_value > current_value)
                {
                    break;
                }
                else if (top_value < current_value)
                {
                    s.pop();
                }
                else
                {
                    s.pop();
                    break;
                }
            }
        }
    }

    if (s.isEmpty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        stack temp(s.getlength());

        while (!s.isEmpty())
        {
            temp.push(s.pop());
        }

        while (!temp.isEmpty())
        {
            cout << temp.pop();
            if (!temp.isEmpty())
            {
                cout << " ";
            }
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