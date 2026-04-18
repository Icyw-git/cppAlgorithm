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
        preOrder(t->left);  // 递归访问左子树
        preOrder(t->right); // 递归访问右子树
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

    void levelOrder(node *t) //层序遍历，意思是按照树的层次从上到下、从左到右依次访问每个节点。实现层序遍历的一种常用方法是使用队列来辅助遍历过程。具体步骤如下：
    {
        queue<node *> q;
        q.push(t);
        while (!q.empty())
        {
            node *tem = q.front(); //获取队列的第一个元素，即当前访问的节点
            q.pop();
            cout << tem->data << ' ';
            if (tem->left)
            {
                q.push(tem->left); //如果当前节点的左子树不为空，则将左子树的根节点加入队列，以便后续访问
            }
            if (tem->right)
            {
                q.push(tem->right); //如果当前节点的右子树不为空，则将右子树的根节点加入队列，以便后续访问
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

    node* find(int x,node *t)
    {
        node *tem;
        if (t==nullptr)
        {
            return nullptr;
        }

        if (t->data == x)
        {
            return t;

        }
        tem = find(x, t->left);
        if (tem)
        {
            return tem;
        }else
        {
            tem = find(x, t->right);
            return tem;

        }
    }

    void delleft(int x)
    {
        node *tem=find(x,root);
        if (tem)
        {
            clear(tem->left);

        }
        else
        {
            return ;
        }

    }

    void delright(int x)
    {
        node *tem=find(x,root);
        if (tem)
        {
            clear(tem->right);

        }
        else
        {
            return ;
        }

    }

    int lchild(int x,int flag)
    {
        node *tem;
        tem=find(x,root);
        if (tem==nullptr||tem->left==nullptr)
        {
            return flag;

        }
        return tem->left->data;

    }

    int rchild(int x,int flag)
    {
        node *tem=find(x,root);
        if (tem==nullptr||tem->right==nullptr)
        {
            return flag;
        }
        return tem->right->data;

    }

    void printtree(binarytree &t,int flag)
    {
        queue<int> q;
        q.push(t.root->data);
        cout<<endl;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();
            int l=t.lchild(data,flag);
            int r=t.rchild(data,flag);
            cout<<data<<' '<<l<<' '<<r<<endl;
            if (l!=-1)
            {
                q.push(l);
            }
            if (r!=-1)
            {
                q.push(r);
            }
        }

    }
};
