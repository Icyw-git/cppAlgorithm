#include<iostream>
using namespace std;

class queue{
    private:

    int *p;
    int maxsize;
    int front;
    int rear;

    public:
    queue(int size){
        p=new int[size];
        maxsize=size;
        front=0;
        rear=0;

    }

    ~queue(){
        delete []p;

    }

    bool isEmpty(){
        return front==rear;

    }

    bool isFull(){
        return (rear+1)%maxsize==front;

    }

    void enqueue(int x){
        if(isFull()){
            return;

        }
        rear=(rear+1)%maxsize;
        p[rear]=x;
    }

    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        front=(front+1)%maxsize;
        return p[front];
    }

    int gethead(){
        if(isEmpty()){
            return -1;

        }
        return p[(front+1)%maxsize];
    }


};

int ticket(int a[],int n,int k){
    queue q(n+1); //这里+1是因为队列中需要一个位置来存储队头元素
    int time=0;

    for(int i=0;i<n;i++){
        q.enqueue(i); //编号入队，票数不动，这里把票数放在编号上

    }

    while(!q.isEmpty()){
        int idx=q.dequeue();
        a[idx]--;
        time++;
        if(a[idx]!=0){
            q.enqueue(idx);
            
        }
        else{
            if(idx==k){
                return time;

            }
            }
        }
        return time;
       

    }





int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<ticket(a,n,k)<<endl;
    return 0;
}