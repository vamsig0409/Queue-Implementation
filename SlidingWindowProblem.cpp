#include<bits/stdc++.h>
using namespace std;

vector<int> MaxWindow(vector<int> &arr,int k){
    deque<int>dq;
    vector<int>res;
    //First Window -
    for(int i=0;i<k;i++){
        //if the prev element in deque is smaller than one to be added they can be removed as they will never be ans
        while(! dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    //Next Windows -
    for(int i=k;i<arr.size();i++){
        int curr=arr[i];
        //Removing the front if window has the 3 elements
        if(dq.front()==(i-k))    //if none of the elements were removed due to it being smaller than the new element
            dq.pop_front();
        //Same as earlier-
        while(! dq.empty() && arr[dq.back()]<arr[i])
            dq.pop_back();

        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    return res;
}

int main(){
    vector<int>v;
    int arr[]={1,3,-1,-3,5,3,6,7};

    for(int i=0;i<8;i++)
        v.push_back(arr[i]);

    int k;
    cin>>k;

    vector<int>ans=MaxWindow(v,k);

    for(int i=0;i<8-k+1;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}