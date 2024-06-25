/*
*   author: kartik8800
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
using namespace std;

int pows[100001];
bool done = 0;

int power10(int n){
    if(!done){
        pows[0] = 1;
        for(int i = 1; i <= 100000; i++)
            pows[i] = (pows[i-1] * 10LL) % mod;
        done = 1;
    }
    return pows[n];
}

int cntdp[100001][2];
int cnt(string& R, int n, bool tight){
    if(tight == 0)return power10(n);
    if(n == 0)return 1;

    if(cntdp[n][tight] != -1)return cntdp[n][tight];

    int ub = R[R.length() - n] - '0';
    ll count = 0;
    for(int dig = 0; dig <= ub; dig++){
        count = (count + cnt(R,n-1,dig == ub)) % mod;
    }
    return cntdp[n][tight] = count % mod;
}

int dp[100001][11][2];
int solve(string& R, int n, int prev_digit, bool tight){
    if(n == 0)
        return 0;

    if(dp[n][prev_digit][tight] != -1)
        return dp[n][prev_digit][tight];

    ll answer = 0;
    int ub = tight ? (R[R.length() - n] - '0') : 9;

    for(int dig = 0; dig <= ub; dig++){
        if(dig != prev_digit){
            ll contri = (dig * (1LL * power10(n - 1) * cnt(R, n - 1, tight & (dig == ub)))) % mod;
            answer = (answer + contri) % mod;
        }
        answer = (answer + solve(R, n-1, dig, tight & (ub == dig))) % mod;
    }

    return dp[n][prev_digit][tight] = answer % mod;
}

int bruteForce(string& L, int nl){
    int prev_dig = 10;
    ll res = 0;
    for(int i = 0; i < L.length(); i++){
        if((L[i] - '0') != prev_dig){
            res = (res + (L[i] - '0') * power10(L.length() - i - 1)) % mod;
        }
        prev_dig = (L[i] - '0');
    }
    return res % mod;
}

int tester(string L, string R){
    int l = atoi(L.c_str());
    int r = atoi(R.c_str());
    cout << l << endl;
    ll result = 0;
    rep(num, l, r+1){
        string number = to_string(num);
        result = (result + bruteForce(number, number.length())) % mod;
    }
    return result;
}

signed main() {
   fast_io;
   int t; cin >> t;
   while(t--){
        int nl; string L; cin >> nl >> L;
        int nr; string R; cin >> nr >> R;
        memset(dp, -1, sizeof dp);
        memset(cntdp, -1, sizeof cntdp);
        ll ansR = solve(R, nr, 10, 1);
        memset(dp, -1, sizeof dp);
        memset(cntdp, -1, sizeof cntdp);
        ll ansL = solve(L, nl, 10, 1);
        cout << (ansR  + (mod - ansL) + bruteForce(L, nl)) % mod << '\n';
   }
   return 0;
}

/*
1
10 9990000000
10 9990009999
458930971
697477500

Process returned 0 (0x0)   execution time : 10.515 s
Press any key to continue.
*/
