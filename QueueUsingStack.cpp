#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    stack<int>q;

    void enqueue(int data){
        q.push(data);
        return;
    }
    void dequeue(){
        if(q.size()==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        stack<int>temp;

        //Copying elements of first stack to another to access the bottom-
        while(! q.empty()){
            temp.push(q.top());
            q.pop();
        }
        temp.pop();
        //Copying again to the stack after removing-
        while(! temp.empty()){
            q.push(temp.top());
            temp.pop();
        }
        return;
    }
    bool isEmpty(){
        return q.empty();
    }
    int top(){
        if(q.size()==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        stack<int>temp;

        //Reversing once to get top of queue which is bottom of stack-
        while(! q.empty()){
            temp.push(q.top());
            q.pop();
        }
        int front=temp.top(); 
        //Reversing stack again-
        while(! temp.empty()){
            q.push(temp.top());
            temp.pop();
        }
        return front;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.dequeue();

    while(! q.isEmpty()){
        cout<<q.top()<<" ";
        q.dequeue();
    }
    
    return 0;
}