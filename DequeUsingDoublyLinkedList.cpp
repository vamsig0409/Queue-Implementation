#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class Deque{
    Node* head;
    Node* tail;

public:
    Deque(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int d){
        Node* newNode=new Node(d);

        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    void push_back(int d){
        Node* newNode=new Node(d);

        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return;
    }
    void pop_front(){
        if(head==NULL){
            cout<<"Empty Deque"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL)    //Only one node existed
            head->prev=NULL;
        temp->next=NULL;
        delete(temp);
        return;
    }
    void pop_back(){
        if(head==NULL){
            cout<<"Empty Deque"<<endl;
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete(temp);
        return;
    }
    bool empty(){
        return head==NULL;
    }
    int front(){
        if(head==NULL){
            cout<<"Empty Deque"<<endl;
            return -1;
        }
        return head->data;
    }
};

int main(){
    Deque d;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(1);
    d.push_front(2);

    d.pop_back();
    d.pop_front();

    while(! d.empty()){
        cout<<d.front()<<" ";
        d.pop_front();
    }
    
    return 0;
}