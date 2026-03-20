#include<bits/stdc++.h>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int>v;

public:
    Queue(){
        back=-1;
        front=-1;
    }
    void enqueue(int data){
        v.push_back(data);
        this->back++;

        if(back==0)
            front=0;
    }
    void dequeue(){
        if(front==back){
            front=-1;
            back=-1;
            v.clear();
            return;
        }
        this->front++;
    }
    int getFront(){
        if(front==-1)
            return -1;
        return v[front];
    }
    bool isEmpty(){
        return front==-1;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.dequeue();
    q.dequeue();

    while(! q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.dequeue();
    }
    
    return 0;
}