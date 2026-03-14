#include<iostream>
using namespace std;

struct Node
{
    Node(int data_=0):data(data_),next(nullptr){}; //构造函数,初始化数据域和指针域
    int data;
    Node* next;

};
class Clink //链表类,实现链表的基本操作
{
private:
    Node* head;
public:
    Clink()
    {
        head=new Node(); //头节点,不存储数据


    }
    ~Clink() //析构函数,释放链表内存
    {

        Node* p=head->next;
        Node* q=head;
        head->next=nullptr;
        while (p!=nullptr)
        {
            q=p->next;
            delete p;
            p=q;
        }
    }
    void inserttail(int val);
    void inserthead(int val);
    void remove(int val);
    void show();
    void reverse();
    int getlastkvalue(int k);
    void mergelinks(Clink &c1,Clink &c2);
    bool involve(Clink &c1,Clink &c2);
    void deletekval(int k);



};

void Clink::inserttail(int val)
{
   Node* p=head;
    while (p->next!=nullptr)
    {
        p=p->next;

    } //遍历到链表末尾
    Node* temp=new Node(val);
    p->next=temp; //将新节点连接到链表末尾


}
void Clink::inserthead(int val)
{
    Node* p=head;
    Node* tem=new Node(val);
    tem->next=head->next; //将新节点的指针域指向头节点的下一个节点
    head->next=tem; //将头节点的指针域指向新节点

}
void Clink::remove(int val)
{
    Node* p=head->next; //从头节点的下一个节点开始遍历
    Node* q=head; //头节点,用于删除操作
    while (p !=nullptr)
    {
        if (p->data==val)
        {
            q->next=p->next; //将前一个节点的指针域指向当前节点的下一个节点
            delete p;
            p=q->next; //将当前节点指向下一个节点

        }
        else
        {
            p=p->next; //将当前节点指向下一个节点
            q=q->next; //将前一个节点指向下一个节点

        }
    }
}
void Clink::reverse()
{
    Node* p=head;
    Node *q=head->next;
    head->next=nullptr; //将头节点的指针域指向空,表示链表结束,然后从第二个节点开始遍历
    while (q !=nullptr)
    {
        inserthead(q->data); //利用头插法倒序
        q=q->next;


    }

}
int Clink::getlastkvalue(int k)
{
    Node* p=head; //从头节点开始遍历，用于遍历到第k个节点
    Node* q=head; //从第二个节点开始遍历
    for (int i=0;i<k;i++)
    {
        if (p==nullptr)
        {
            return -1;
        }
        else
        {
            p=p->next; //将当前节点指向下一个节点，遍历到第k个节点

        }
    }
    while (p!=nullptr)
    {
        p=p->next;
        q=q->next;

    } //遍历到链表末尾,返回第k个节点的数据
    return q->data;
}

void Clink::show()
{
    Node* p=head->next;
    while (p!=nullptr) //遍历链表,打印每个节点的数据
    {
        cout<<p->data<<' ';
        p=p->next;


    }
    cout<<endl;

}

void Clink::mergelinks(Clink &c1,Clink &c2) //合并两个有序链表,思路:使用双指针,分别指向两个链表的头节点,比较两个指针指向的节点的数据,将较小的节点连接到合并后的链表的最后一个节点,然后将指向较小节点的指针指向下一个节点,重复此过程,直到其中一个链表为空,将另一个链表的剩余节点连接到合并后的链表的最后一个节点
{
    Node *p=c1.head->next;
    Node *q=c2.head->next;
    Node *last=c1.head; //指向c1链表的最后一个节点,用于连接c2链表的节点
    c2.head->next=nullptr; //将c2链表的头节点的指针域指向空,表示链表结束,然后从第二个节点开始遍历


    while (p!=nullptr && q!=nullptr)
    {
        if (p->data>=q->data)
        {
            last->next=q;
            q=q->next;
            last=last->next;


        } //将c2链表的节点连接到c1链表的最后一个节点
        else
        {
            last->next=p;
            p=p->next;
            last=last->next;
        } //将c1链表的节点连接到c2链表的最后一个节点
    }
    if (p!=nullptr)
    {
        last->next=p; //将c1链表的剩余节点连接到c2链表的最后一个节点
    }
    if (q!=nullptr)
    {
        last->next=q; //将c2链表的剩余节点连接到c1链表的最后一个节点
    }
}
// 判断两链表是否存在环，思路：使用快慢指针,快指针每次移动两步,慢指针每次移动一步,如果快指针追上慢指针,则表示链表存在环,如果快指针到达链表末尾,则表示链表不存在环
bool cycle(Node* head,int &val)
{
    Node* p=head;
    Node* q=head;
    while (p!=nullptr && p->next !=nullptr) //判断链表是否存在环
    {
        p=p->next->next; //快指针每次移动两步
        q=q->next; //慢指针每次移动一步
        if (p==q)
        {

            p=head; //将快指针指向头节点,用于找到环的入口节点
            while (p!=q)
            {
                p=p->next;
                q=q->next;


            }
            val=p->data;
            return true; //返回环的入口节点的数据

        }

    }
    return false; //返回false,表示链表不存在环


}

bool involve(Node *head1,Node *head2) //判断两链表是否相交,思路:计算两个链表的长度,将较长的链表指针移动到与较短链表指针相同的位置,然后同时移动两个指针,如果相遇,则表示相交
{
    int cnt1=0;
    int cnt2=0;
    Node *p=head1;
    Node *q=head2;
    while (p!=nullptr)
    {
        p=p->next;
        cnt1++;

    }
    while (q!=nullptr)
    {
        q=q->next;
        cnt2++;

    }
    if (cnt1>cnt2)
    {
        int offset=cnt1-cnt2;
        p=head1;
        q=head2;

        while (offset>0)
        {
            p=p->next;
            offset--;

        }
        while (p!=nullptr &&q!=nullptr)
        {

            if (p==q)
            {
                return true;
            }
            p=p->next;
            q=q->next;
        }
        return false;
    }
    else
    {
        int offset=cnt2-cnt1;
        p=head1;
        q=head2;

        while (offset>0)
        {
            q=q->next;
            offset--;

        }
        while (q!=nullptr && p!=nullptr)
        {

            if (p==q)
            {
                return true;
            }
            p=p->next;
            q=q->next;
        }
        return false;
    }

}

void Clink::deletekval(int k)
{
    Node *p=head;
    Node *q=head;
    for (int i=0;i<=k;i++)
    {
        p=p->next;
        if (p==nullptr)
        {
            return;
        }

    }
    while (p!=nullptr)
    {
        p=p->next;
        q=q->next;


    }
    Node *q1=q->next;
    q->next=q1->next;
    delete q1;

}

int main()
{
    Clink a;
    a.inserttail(10);
    a.inserttail(10);

    a.inserttail(20);
    a.show();
    a.inserthead(30);
    a.show();
    a.remove(10);
    a.show();
    a.reverse();
    a.show();
    cout<<a.getlastkvalue(1);

    int a1[6]={15,38,26,162,37,21};
    int a2[4]={23,43,12,54};
    Clink b;
    Clink c;
    for (int x:a1)
    {
        b.inserttail(x);
    }
    for (int x:a2)
    {
        c.inserttail(x);
    }
    b.show();
    c.show();
    b.mergelinks(b,c);
    b.show();
    b.deletekval(2);
    b.show();

    Node *p0=new Node();
    Node *p1=new Node(2);
    p0->next=p1;
    Node *p2=new Node(3);
    p1->next=p2;
    Node *p3=new Node(4);
    p2->next=p3;
    Node *p4=new Node(5);
    p3->next=p4;
    p4->next=p2;
    int k;

    cout<<cycle(p0,k)<<endl;

    cout<<k<<endl;
    //
    Node n1(12),n2(22),n3(34),n4(33),n5(44);
    Node head1;
    Node head2;
    head1.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    head2.next=&n4;
    n3.next=&n5;
    n4.next=&n2;
    cout<<involve(&head1,&head2);





}
