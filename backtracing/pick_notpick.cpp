//endhulo subsequence pick ana not pick way lo cheyali
//question enti ante 
//echchina sequence lo subsequence lo enni summations equal to k avutayi 
//recurssiion lo pick not pick cheyadam vachchu ga alane.
//standard subsequence property 
#include<iostream>
using namespace std;
void function_for_subsequence(int index,int highest_range,vector<int>&v,vector<int>temp){
    if(index>=highest_range){
        cout<<"{";
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<"}";
        return ;
    }
    //take 
    temp.push_back(v[index]);
    function_for_subsequence(index+1,highest_range,v,temp);

    //not take
    temp.pop();
    function_for_subsequence(index+1,highest_range,v,temp);

}
void function_for_kth_sum_subsequence(int index,int highest_range,int k,int current_sum,vector<int>&v,int &count){
if(index>=highest_range){
    if(current_sum==k){
        count++;
    }
}
current_sum+=v[index];
index++;
function_for_kth_sum_subsequence(index,highest_range,k,current_sum,v,count);
current_sum-=v[index];
function_for_kth_sum_subsequence(index,highest_range,k,current_sum,v,count);

}

int main(){
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
vector<int>temp;
//function_for_subsequence(0,n,v,temp);



return 0;}