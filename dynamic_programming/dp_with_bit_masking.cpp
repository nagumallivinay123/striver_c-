#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define div 1000000007
	map<ll,ll> m;
	vector<ll> prime={5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

ll fact(ll a){
	set<ll> s;
  	for(ll i=2;i<a;i++){
		if(a%i==0){
			s.insert(i);
		}
	}
	ll ans=1;
	for(auto x:s){
		ll bit=m[x];
		ans=ans+(1<<bit);
	}
	return ans;
}
ll check(ll a){
   
    for(size_t i=0;i<prime.size();i++)
    {
        if(a%prime[i]==0)
        return 0;
    }
    return 1;
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> v;
	v.push_back(1);
	for(ll i=2;i<=n;i++){
		if(check(i)){
		    v.push_back(i);
		}
	}

	ll limit=v.size();

vector<vector<ll>>dp(limit,vector<ll>(1<<limit,0));
	for(ll i=0;i<limit;i++){
		m[v[i]]=i;
	}
	dp[0][1]=1;

	for(ll i=1;i<limit;i++)
    {
		for(ll j=0;j<(1<<limit);j++)
        {
		    
		   for(ll k=0;k<limit;k++){
			   ll a=v[k];
			   ll idx=m[v[k]];
			   ll mask=(1<<idx);
			   if((mask&j)==0){
				   ll al=fact(a);
				   if((al|j)==j)
                   {
                    dp[i][mask|j] += dp[i-1][j];
				   }
				   
			   }
		   }
		}
	}

	unsigned ll ans=0;
	
		if(__builtin_popcount(j)==(limit))ans=ans+dp[limit-1][j];
	
	cout<<ans<<endl;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t=1;
  //cin >> t;
  while(t--){
	  solve();
  }	
}