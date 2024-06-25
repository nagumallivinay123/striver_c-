#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    priority_queue<int>q;
    cin>>n;
    int k;
    cin>>k;
//to find kth_smallest_element_in_prioriry_queue_in_c++ we should implement max_heap
//c++ lo max heap inbuilt function by priority_queue
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        q.push(a);

    }
    for(int i=k;i<=n;i++){
        int a;
        cin>>a;
        if(a<(q.top())){
           q.pop();
           q.push(a);
        }
    }
cout<<"kth_largeset_element_is_="<<q.top();
    return 0 ;
}