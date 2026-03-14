//
// Created by icyw on 2026/3/14.
//
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data=0):data(data),next(nullptr){};
};

class Clink
{
private:
    Node *head;
    int length;
    int currentlength;

public:
    Clink(int length_)
    {
        length=length_;
        head=new Node();
        currentlength=0;

    }
    ~Clink()
    {
        Node *p=head;
        while (p !=nullptr)
        {
            head=head->next;

            delete p;
            p=head;

        }

    }
    void inserttail(int val);
    void inserthead(int val);
    void reverse();
    void reverse1();
    void display();
    void plus(Clink &c1,Clink &c2);



};

void Clink::inserttail(int val)
{
    Node *p=head;
    while (p->next !=nullptr)
    {
        p=p->next;

    }
    Node *tem=new Node(val);
    p->next=tem;
    currentlength++;


}

void Clink::inserthead(int val)
{
    Node *p=head->next;
    Node *tem=new Node(val);
    tem->next=p;
    head->next=tem;
    currentlength++;
}

void Clink::display()
{
    Node *p=head;
    while (p->next !=nullptr)
    {
        p=p->next;
        cout<<p->data<<" ";
    }
}

void Clink::reverse() //链表倒序,思路:使用三个指针prev,current,next,prev指向当前节点的前一个节点,current指向当前节点,next指向当前节点的下一个节点,将current节点的指针域指向prev,然后将prev,current,next依次向后移动,直到current指向空,最后将头节点的指针域指向prev
{
    Node *prev = nullptr;
    Node *current = head->next;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head->next = prev;
}

void Clink::plus(Clink &c1,Clink &c2) //链表加法,思路:先将两个链表倒序,然后使用双指针分别指向两个链表的头节点,将两个节点的数据相加,如果和大于等于10,则将和减去10,并将进位加到下一次相加的结果中,最后将结果插入到新链表的头部,直到两个链表都遍历完,如果还有进位,则将进位插入到新链表的头部
{
    c1.reverse();
    c2.reverse();
    Node *p=c1.head->next;
    Node *q=c2.head->next;
    Clink d(100);
    int sum=0;
    while (p!=nullptr || q!=nullptr || sum!=0)
    {
        if (p!=nullptr)
        {
            sum+=p->data;
            p=p->next;
        }
        if (q!=nullptr)
        {
            sum+=q->data;
            q=q->next;
        }
        d.inserthead(sum%10);
        sum/=10;
    }
    d.display();

}




int main()
{


    int m,n;
    cin>>m>>n;
    Clink a(m),b(n);

    for (int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        a.inserttail(val);
    }
    for (int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        b.inserttail(val);
    }
    a.plus(a,b);



}

