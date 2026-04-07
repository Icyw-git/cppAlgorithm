//题目描述：
//输入一个整数，所有元素向右移动k位

#include<iostream>
using namespace std;

template<class elemtype>
class linklist
{
    struct Node
    {
        elemtype data;
        Node *next;
        Node(elemtype data_=0)
        {
            data=data_;
            next=nullptr;
        }
    };
    Node *head;
    int length;
public:
    linklist()
    {
        head=new Node();
        length=0;
    }


    void show()
    {
        Node *p=head;
        while (p->next !=nullptr)
        {
            p=p->next;

            cout<<p->data<<' ';
        }
    }

    void inserttail(elemtype val)
    {
        Node *p=head;
        while (p->next !=nullptr)
        {
            p=p->next;
        }
        Node *tem=new Node(val);
        p->next=tem;
        length++;
    }

    int getlength()
    {
        return length;

    }

    void rotate(linklist<int> &l,int k )
    {
        Node *p=l.head;
        Node *q=l.head;

        while (p->next!=nullptr)
        {
            p=p->next;

        }
        p->next=l.head->next;
        for (int i=0;i<=l.getlength()-k;i++)
        {
            q=q->next;

        }

        for (int i=0;i<l.getlength();i++)
        {
            cout<<q->data<<" ";
            q=q->next;

        }



    }

};

int main()
{
    linklist<int> l;
    int k ;
    cin>>k;
    for (int i=0;i<5;i++)
    {
        l.inserttail(i);
    }
    l.show();
    cout<<endl;
    l.rotate(l,k);
}


