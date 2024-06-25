#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const long long mod=1e9+7;
void solve()
{
/*function ekkada rasukovadani */
ll n;
cin>>n;
vector<ll>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
ll left=0;
ll right=n-1;
ll sum=0;
ll ans=0;
sort(arr.begin(),arr.end());
while(left<right)
{
    while(sum<arr[right] && left<right)
    {
        sum+=arr[left];
        arr[left]=0;
        left++;

    }
    if(sum<arr[right])
    { 
        ans+=arr[right]+1;
    
        left++;
        break;
    }
    
  
    ans+=(arr[right]+1);
    arr[right]=0;
    sum=sum-arr[right];
    right--;   
}
if(left==right){
    ans+=arr[left];
}
cout<< ans;





}

int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
 int t;
 cin>>t;

   while(t--)
   {
      solve();
      cout<<"\n";
   }

return 0;}