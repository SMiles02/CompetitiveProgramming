// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n,m,k,x;
    cin>>n>>k;
    vector<int> pos, neg;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (x>0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
    pos.push_back(0);
    neg.push_back(0);
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    n=sz(pos);
    m=sz(neg);
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n+m, vector<ll>(2, 1e18)));
    // dp[pos/neg][i][return or not]
    dp[0][0][0]=dp[0][0][1]=dp[1][0][0]=dp[1][0][1]=0;
    // cout<<"pos:\n";
    for (int i=1;i<n;++i)
    {
        dp[0][i][0]=dp[0][max(i-k,0)][1]+pos[i];
        dp[0][i][1]=dp[0][max(i-k,0)][1]+pos[i]*2;
        // cout<<pos[i]<<" "<<dp[0][i][0]<<" "<<dp[0][i][1]<<"\n";
    }
    // cout<<"neg:\n";
    for (int i=1;i<m;++i)
    {
        dp[1][i][0]=dp[1][max(i-k,0)][1]+abs(neg[i]);
        dp[1][i][1]=dp[1][max(i-k,0)][1]+abs(neg[i]*2);
        // cout<<dp[1][i][0]<<" "<<dp[1][i][1]<<"\n";
    }
    cout<<min(dp[0][n-1][0]+dp[1][m-1][1],dp[0][n-1][1]+dp[1][m-1][0])<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}