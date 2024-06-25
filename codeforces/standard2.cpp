#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
void solve()
{
    /*function ekkada rasukovadani */
  int n,m;
  cin>>n>>m;
 
  string x;
  string b;
  
  cin>>x;
  cin>>b;
  if(x==b){
    cout<<0;
    return ;
  }
   int max_time=n;
   if(n<m){
    max_time=n*(m/n+1);
   }

   max_time=2*max_time;
//    cout<<max_time<<" ";
// cout<<x<<b<<" ";
   int ans=-1;
  int j=0;
  int i=0;
//   cout<<max_time<<" ";
    while(i<max_time)
    {

        // cout<<x[i%n]<<" ";
        if(x[i%n]!=b[j])
        {
            
            j=0;
            i++;
            continue;
        }
      

        while(j<m && i<max_time && x[i%n]==b[j])
        {
        
            // cout<<i<<" "<< j<<" "<<  x[i%n]<<" "<< b[j]<<"\n";
            
            i++;
            j++;
            // cout<<"second"<<"\n";
            // cout<<i<<" "<< j<<" "<< x[i%n]<<" "<<b[j]<<"\n";
            // cout<<"\n\n";
        }
        
        
        if(j==m)
        {
          ans=i;
          break;
        }
        else
        {
            j=0;
        }
        
    }
    int op=0;
    int some=n;
    if(ans==-1){
    cout<<ans;
    }
    else{

// cout<<"ans ="<<ans<<"\n";
    while(ans>some)
    {
          some=some*2;
         
          op++;
    }

    cout<< op;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}