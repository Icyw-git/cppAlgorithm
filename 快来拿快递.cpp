//
// Created by icyw on 2026/4/11.
//

#include<iostream>
using namespace std;

class stack
{
private:
    int *data;
    int top_p;
    int maxsize;

public:
    stack(int size)
    {
        data= new int[size];
        top_p=-1;
        maxsize=size;

    }
    ~stack()
    {
        delete[]data;

    }
    void push(int x)
    {
        if(top_p==maxsize-1)
        {
            return;
        }
        top_p=top_p+1;
        data[top_p]=x;
    }
    int pop()
    {
        if(top_p==-1)
        {
            return -1;
        }
        int tem=data[top_p];
        top_p--;
        return tem;

    }
    int top()
    {
        if(top_p==-1)
        {
            return -1;


        }
        return data[top_p];
    }
    bool isEmpty()
    {
        return top_p==-1;

    }
    bool isFull()
    {
        return top_p==maxsize-1;
    }

};

template <class elemtype>
class linkqueue //链接队列的实现
{
private:
    struct Node
    {
        elemtype data;
        Node* next;

        Node(elemtype data_ = 0)
        {
            data = data_;

            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:
    linkqueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~linkqueue()
    {
        while (front !=nullptr)
        {
            Node *temp=front;
            front =front->next;
            delete temp;

        }
        rear=nullptr;

    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(const elemtype& x)
    {
        if (isEmpty())
        {
            front = rear = new Node(x);
            return;
        }
        Node* tem = new Node(x);
        rear->next = tem;
        rear = tem;
    }

    elemtype dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        elemtype val = front->data;
        front = front->next; //移动front指针至下一个节点
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return val;
    }

    elemtype gethead()
    {
        if (isEmpty())
        {
            return -1;
        }
        elemtype val = front->data;
        return val;
    }
};



int main()
{
    int K;
    cin>>K;
    int M;
    cin >> M;
    linkqueue<int> q;
    stack s(K);
    int count=0; //总的移动次数

    for (int i = 0; i < M; i++)
    {
        string str;
        cin>>str;
        if (str=="ARRIVE")
        {
            int x;
            cin>>x;
            q.enqueue(x);
            while (!s.isFull() && !q.isEmpty()) //当货架不满且等待队列不为空的时候 让等待的货物进入货架
            {
                s.push(q.dequeue()); //更新等待队列
            }

        }
        if (str=="PICKUP")
        {
            int x;
            cin>>x;
            stack tem(K);
            int moved = 0; //该轮的移动次数
            while (!s.isEmpty() && s.top() != x)
            {
                tem.push(s.pop());
                moved++;
            }
            if (!s.isEmpty())
            {
                s.pop();
                while (!tem.isEmpty())
                {
                    s.push(tem.pop());
                }
                count += 2 * moved; //如果找到目标货物就加在总的移动次数上 乘2是因为每次移动都要把货物拿出来再放回去
            }
            else
            {
                while (!tem.isEmpty())
                {
                    s.push(tem.pop()); //直接放回去 不需要加移动次数
                }
            }

            while(!s.isFull() && !q.isEmpty())
            {
                s.push(q.dequeue()); //更新等待队列
            }




        }
    }
    if (s.isEmpty())
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        stack tem(K);
        while (!s.isEmpty())
        {
            tem.push(s.pop());
        }
        while (!tem.isEmpty()) //把货架上的货物按照从底到顶的顺序输出
        {
            cout<<tem.pop()<<' ';
        }
        cout<<endl;
    }

    if (q.isEmpty())
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        while (!q.isEmpty())
        {
            cout<<q.dequeue()<<" ";

        }
        cout<<endl;

    }

    cout<<count<<endl;


}