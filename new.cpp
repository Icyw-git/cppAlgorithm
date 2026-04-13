
#include<iostream>
#include<string>
using namespace std;

int minimumRecolors(string blocks, int k) {
    int ans=k;
    int count=0;
    for(int i=0;i<blocks.size();i++){
        if(i-k+1<0){
            if(blocks[i]=='W'){
                count++;
                continue;
            }

        }
        if(blocks[i]=='W'){
            count++;
        }
        ans=min(ans,count);
        if(blocks[i-k+1]=='W'){
            count--;
        }

    }
    return ans;

}

int main()
{
    int k;
    string blocks;
    cin>>blocks>>k;
    cout<<minimumRecolors(blocks,k)<<endl;
}