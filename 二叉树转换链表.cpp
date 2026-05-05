//
// Created by icyw on 2026/4/28.
//


#include<iostream>
#include <queue>
using namespace std;


class binarytree
{
private:
    struct TreeNode
    {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data_, TreeNode *left_ = nullptr, TreeNode *right_ = nullptr)
        {
            data = data_;
            left = left_;
            right = right_;
        }

    };
    TreeNode *root;

    public:
        binarytree()
        {
            root=nullptr;

        }

    ~binarytree()
    {
        clear(root);
    }

    void clear(TreeNode *node)
        {
            if (node != nullptr)
            {
                clear(node->left);
                clear(node->right);
                delete node;

            }
        }

    bool isEmpty(TreeNode *root)
        {
            return root == nullptr;
        }

    int Root(TreeNode *root)
        {
            if (isEmpty(root))
            {
                return -1;
            }
            return root->data;
        }

    void PreOrder(TreeNode *t)
        {
            if (t == nullptr)
            {
                return;
            }
            cout<<t->data<<" "; //访问根节点

            PreOrder(t->left);
            PreOrder(t->right);
        }

    void inOrder(TreeNode *t)
        {
            if (t == nullptr)
            {
                return;

            }
            inOrder(t->left);
            cout<<t->data<<" "; //访问根节点
            inOrder(t->right);
        }
    void postOrder(TreeNode *t)
        {
            if (t == nullptr)
            {
                return;
            }
            postOrder(t->right);
            postOrder(t->left);
            cout<<t->data<<" "; //访问根节点
        }

    void levelOrder(TreeNode *t)
        {
            queue<TreeNode *> q;
            q.push(t);
            while (!q.empty())
            {
                TreeNode* tem=q.front();
                q.pop();
                cout<<tem->data<<" "; //访问当前节点
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

    void createBinaryTree(int flag)
        {
            queue<TreeNode *> q;
            int x;
            int ldata, rdata;
            cout<<"输入根节点："<<endl;
            cin>>x;
            root=new TreeNode(x);
            q.push(root);
            while (!q.empty())
            {
                TreeNode *temp=q.front();
                q.pop();
                cout<<"输入节点："<<temp->data<<"的左右节点"<<endl;
                cin>>ldata>>rdata;
                if (ldata!=flag)
                {
                    temp->left=new TreeNode(ldata);
                    q.push(temp->left);
                }
                if (rdata!=flag)
                {
                    temp->right=new TreeNode(rdata);
                    q.push(temp->right);
                }
            }
        }


};

int main()
{
    binarytree t;
    int flag=0;
    t.createBinaryTree(flag);

}