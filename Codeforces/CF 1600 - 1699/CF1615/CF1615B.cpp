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

const int N = 2e5+1;
int p[N][20];

void solve() {
    int l,r,ans=N;
    cin>>l>>r;
    for (int i=0;i<20;++i)
        ans=min(ans,r-l+1-p[r][i]+p[l-1][i]);
    cout<<ans<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;++i)
        for (int j=0;j<20;++j)
            p[i][j]=p[i-1][j]+min(1,i&(1<<j));
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}