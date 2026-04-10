//
// Created by icyw on 2026/3/14.
//
//reverse:题目描述
// 给定一组整数，请先根据这些整数构建一个链表，再将链表逆置，最后输出逆置后的链表。
//
// 输入格式
// 第一行，输入一个正整数 n，表示链表中结点的个数。
//
// 第二行，输入 n 个整数，表示链表中各结点的初始值。
//
// 输出格式
// 输出一行，共 n 个数，表示链表逆置后的结果。

// //plus:题目描述
// 给定两个非空链表表示两个非负整数，链表的一个节点的值代表数字的一位，求这两个数字的和，和也用链表的形式给出。
//
// 输入格式
// 第一行：整数m和n，表示两个非负整数的位数
//
// 第二行：第一个非负整数每一位的值
//
// 第三行：第二个非负整数每一位的值
//
// 输出格式
// 第一行：两个非负整数用链表表述的和


#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data = 0) : data(data), next(nullptr)
    {
    };
};

class Clink
{
private:
    Node* head;
    int length;
    int currentlength;

public:
    Clink(int length_)
    {
        length = length_;
        head = new Node();
        currentlength = 0;
    }

    ~Clink()
    {
        Node* p = head;
        while (p != nullptr)
        {
            head = head->next;

            delete p;
            p = head;
        }
    }

    void inserttail(int val);
    void inserthead(int val);
    void reverse();
    void reverse1();
    void display();
    void plus(Clink& c1, Clink& c2);
};

void Clink::inserttail(int val)
{
    Node* p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    Node* tem = new Node(val);
    p->next = tem;
    currentlength++;
}

void Clink::inserthead(int val)
{
    Node* p = head->next;
    Node* tem = new Node(val);
    tem->next = p;
    head->next = tem;
    currentlength++;
}

void Clink::display()
{
    Node* p = head;
    while (p->next != nullptr)
    {
        p = p->next;
        cout << p->data << " ";
    }
}

void Clink::reverse()
//链表逆置：利用三个指针prev、current和next，prev指向当前节点的前一个节点，current指向当前节点，next指向当前节点的下一个节点，在遍历链表的过程中，将current节点的指针域指向prev节点，然后将prev、current和next依次向后移动，直到current节点为nullptr，此时prev节点就是链表的最后一个节点，将头节点的指针域指向prev节点即可实现链表的逆置
{
    Node* prev = nullptr; //指向当前节点的前一个节点
    Node* current = head->next; //指向当前节点，从头节点的下一个节点开始遍历
    Node* next = nullptr; //指向当前节点的下一个节点
    while (current != nullptr)
    {
        next = current->next; //更新指向当前节点的下一个节点的指针
        current->next = prev; //当前节点的后继为前一个节点
        prev = current; //指针向后移动，prev指向当前节点
        current = next; //指针向后移动，current指向下一个节点
    }
    head->next = prev; //最后将头指针的指针域指向prev节点，即链表的最后一个节点，实现链表的逆置
}


void Clink::plus(Clink& c1, Clink& c2)
//链表加法,思路:先将两个链表倒序,然后使用双指针分别指向两个链表的头节点,将两个节点的数据相加,如果和大于等于10,则将和减去10,并将进位加到下一次相加的结果中,最后将结果插入到新链表的头部,直到两个链表都遍历完,如果还有进位,则将进位插入到新链表的头部
{
    c1.reverse(); //翻转链表，便于进位
    c2.reverse();
    Node* p = c1.head->next;
    Node* q = c2.head->next; //指向个位
    Clink d(100);
    int sum = 0;
    while (p != nullptr || q != nullptr || sum != 0) //当某位数有数字或者有进位的时候继续循环
    {
        if (p != nullptr)
        {
            sum += p->data;
            p = p->next;
        }
        if (q != nullptr)
        {
            sum += q->data;
            q = q->next;
        }
        d.inserthead(sum % 10);
        sum /= 10;
    }
    d.display();
    c1.reverse(); //将链表恢复原来的顺序
    c2.reverse();
}

void Clink::reverse1() //链表逆置：利用头插法，将链表中的每个节点依次插入到头节点的下一个位置，最终实现链表的逆置
{
    Node* p = head->next; //从头节点的下一个节点开始遍历
    if (p == nullptr)
    {
        return;
    }
    head->next = nullptr;
    while (p != nullptr)
    {
        Node* q = p->next; //将当前节点的下一个节点保存到q中
        p->next = head->next; //将当前节点的指针域指向头节点的下一个节点
        head->next = p; //将头节点的指针域指向当前节点
        p = q; //将当前节点指向下一个节点
    }
}


int main()
{
    int m, n;
    cin >> m >> n;
    Clink a(m), b(n);

    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        a.inserttail(val);
    }
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        b.inserttail(val);
    }
    a.plus(a, b);
    b.reverse();
    b.display();
}
