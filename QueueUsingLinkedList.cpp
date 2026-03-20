#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;

public:
    Queue(){
        this->head=NULL;
        this->tail=NULL;
        size=0;
    }
    void enqueue(int data){
        Node* newNode=new Node(data);

        if(this->head==NULL){
            this->head=newNode;
            this->tail=newNode;
            size++;
            return;
        }

        tail->next=newNode;
        tail=newNode;
        size++;
        return;
    }
    void dequeue(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }

        Node* temp=head;
        head=head->next;
        if(head==NULL)
            tail=NULL;
        temp->next=NULL;
        size--;

        delete(temp);
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return this->head==NULL;
    }
    int front(){
        if(head==NULL)
            return -1;
        return head->data;
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
        cout<<q.front()<<" ";
        q.dequeue();
    }
    
    return 0;
}