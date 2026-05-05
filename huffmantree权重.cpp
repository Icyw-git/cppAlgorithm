//
// Created by icyw on 2026/5/5.
//

#include<iostream>
using namespace std;


struct node
{
    int left;
    long long weight;
    int right;

};

long long wpl=0;


void dfs(int root ,int depth,node arr[]) //使用递归算法计算depth
{
    if (arr[root].left==0 && arr[root].right==0) //计算叶子节点的weight
    {
        wpl+=arr[root].weight*depth;
        return ;

    }

    if (arr[root].left!=0) //计算该节点的左子树的wpl
    {
        dfs(arr[root].left,depth+1,arr);

    }
    if (arr[root].right!=0) //计算该节点的右子树的wpl
    {
        dfs(arr[root].right,depth+1,arr);
    }
}




int main()
{
    int n;
    cin>>n;
    struct node arr[n+1];
    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i].left;
        cin>>arr[i].weight;
        cin>>arr[i].right;

    }
    bool is_child[n+1]={false}; //找到根节点
    for (int i=1;i<n+1;i++ )
    {
        if (arr[i].left!=0)
        {
            is_child[arr[i].left]=true;
        }
        if (arr[i].right!=0)
        {
            is_child[arr[i].right]=true;
        }
    }

    int root=-1;
    for(int i=1;i<n+1;i++)
    {
        if (!is_child[i])
        {
            root=i;
            break;

        }
    }

    dfs(root,0,arr);
    cout<<wpl<<endl;






}