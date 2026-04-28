//
// Created by icyw on 2026/4/21.
//

#include <iostream>
using namespace std;

class hftree
{
private:
    struct node
    {
        char data;
        int weight;
        int parent, left, right;
    };
    node *elem;
    int length;

public:
    struct hfnode
    {
        char data;
        string code;
    };
    hftree(const char *v, const int *w, int size);
    void getCode(hfnode result[]);
    ~hftree()
    {
        delete[] elem;
    }
};

hftree::hftree(const char *v, const int *w, int size)
{
    const int max_int = 32767;
    int min1, min2;
    int x, y;

    length = 2 * size;
    elem = new node[length];
    for (int i = size; i < length; i++)
    {
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }

    for (int i = size - 1; i > 0; i--)
    {
        min1 = min2 = max_int;

        x = y = 0;
        for (int j = i + 1; j < length; j++)
        {
            if (elem[j].parent == 0)
            {
                if (elem[j].weight < min1)
                {
                    min2 = min1;
                    min1 = elem[j].weight;
                    x = y;
                    y = j;
                }
                else if (elem[j].weight < min2)
                {
                    min2 = elem[j].weight;
                    x = j;
                }

                elem[i].weight = min1 + min2;
                elem[i].left = x;
                elem[i].right = y;
                elem[i].parent = 0;
                elem[x].parent = i;
                elem[y].parent = i;
            }
        }
    }
}

void hftree::getCode(hfnode result[])
{
    int size = length / 2;
    int p, s;

    for (int i = size; i < length; i++)
    {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent;
        s = i;
        while (p)
        {
            if (elem[p].left == s)
            {
                result[i - size].code = "0" + result[i - size].code;
            }
            else
            {
                result[i - size].code = "1" + result[i - size].code;
            }
            s = p;
            p = elem[p].parent;
        }
    }
}