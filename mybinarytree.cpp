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
    void createtree(int flag) //用flag表示空节点 例如输入-1表示该节点为空 构建思路是先输入根节点的值，然后依次输入每个节点的左右子树的值，如果某个子树为空则输入flag，利用队列来辅助构建二叉树。具体步骤如下：
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

    node* find(int x,node *t) //find函数的思路是递归地在二叉树中查找值为x的节点。首先检查当前节点t是否为nullptr，如果是，则返回nullptr表示未找到。如果当前节点的data等于x，则返回当前节点t表示找到了目标节点。否则，先在左子树中递归调用find函数，如果在左子树中找到了目标节点，则返回该节点；如果在左子树中未找到，则继续在右子树中递归调用find函数，并返回结果。这样就可以遍历整个二叉树来查找目标节点。
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

    void delleft(int x) //delleft函数的功能是删除值为x的节点的左子树。首先调用find函数在二叉树中查找值为x的节点，如果找到了该节点，则调用clear函数来释放该节点的左子树的内存，并将该节点的left指针设置为nullptr，表示该节点不再有左子树。如果未找到值为x的节点，则直接返回，不进行任何操作。
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

    int lchild(int x,int flag) //lchild函数的功能是返回值为x的节点的左子节点的值。如果找到了值为x的节点，并且该节点有左子树，则返回左子树根节点的data值；如果找到了值为x的节点，但该节点没有左子树，或者未找到值为x的节点，则返回flag表示没有左子节点。
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
