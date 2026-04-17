#include <iostream>
using namespace std;
#include <queue>

class binarytree
{
private:
    struct node
    {
        int data;
        node *left;
        node *right;
        node(int data, node *left = nullptr, node *right = nullptr)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };
    node *root;

public:
    binarytree()
    {
        root = nullptr;
    }
    ~binarytree()
    {
        clear(root);
    }
    void clear(node *root)
    {
        if (root != nullptr) // 释放该节点的内存，递归至左右子树的节点
        {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
    bool isEmpty(node *root)
    {
        return (root == nullptr);
    }
    int Root(node *root)
    {
        if (isEmpty(root))
        {
            return -1;
        }
        return root->data;
    }

    void preOrder(node *t)
    {
        if (t == nullptr)
        {
            return;
        }

        cout << t->data << " "; // 访问根节点
        preOrder(t->left);
        preOrder(t->right);
    }
    void inOrder(node *t)
    {
        if (t == nullptr)
        {
            return;
        }
        inOrder(t->left);
        cout << t->data << ' ';
        inOrder(t->right);
    }

    void postOrder(node *t)
    {
        if (t == nullptr)
        {
            return;
        }
        postOrder(t->right);
        postOrder(t->left);
        cout << t->data << ' ';
    }

    void levelOrder(node *t)
    {
        queue<node *> q;
        q.push(t);
        while (!q.empty())
        {
            node *tem = q.front();
            q.pop();
            cout << tem->data << ' ';
            if (tem->left)
            {
                q.push(tem->left);
            }
            if (tem->right)
            {
                q.push(tem->right);
            }
        }
    }
    void createtree(int flag)
    {

        queue<node *> q;
        node *temp;
        int x, ldata, rdata;

        cout << "输入根节点：" << endl;
        cin >> x;
        root = new node(x);
        q.push(root);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            cout << "输入节点：" << temp->data << "的左右节点" << endl;
            cin >> ldata >> rdata;
            if (ldata != flag)
            {
                temp->left = new node(ldata);
                q.push(temp->left);
            }
            if (rdata != flag)
            {
                temp->right = new node(rdata);
                q.push(temp->right);
            }
        }
    }
};
