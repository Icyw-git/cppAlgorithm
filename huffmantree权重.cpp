//
// Created by icyw on 2026/5/5.
//

#include<iostream>
using namespace std;
#include<queue>


struct node
{
    int left;
    long long weight;
    int right;

};

long long wpl=0;


void dfs(int root ,int depth,node arr[])
{
    if (arr[root].left==0 && arr[root].right==0)
    {
        wpl+=arr[root].weight*depth;
        return ;

    }

    if (arr[root].left!=0)
    {
        dfs(arr[root].left,depth+1,arr);

    }
    if (arr[root].right!=0)
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
    bool is_child[n+1]={false};
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