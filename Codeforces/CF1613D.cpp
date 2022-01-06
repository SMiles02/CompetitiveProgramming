// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

int sub(int a, int b) { return add(a,MOD-b); }

void solve() {
    int n,k,ans=0;
    cin>>n;
    vector<vector<int>> m(n+3, vector<int>(2));
    // {x,y} => MEX of x, with y denoting if MEX+1 done or not
    while (n--)
    {
        cin>>k;
        if (k>0)
        {    
            ans=add(ans,m[k-1][0]);
            ans=add(ans,m[k-1][1]);
        }
        ans=add(ans,m[k][0]);
        ans=add(ans,m[k+1][0]);
        ans=add(ans,m[k+1][1]);
        if (k>0)
            m[k-1][1]=add(mul(m[k-1][1],2),m[k-1][0]);
        m[k+1][0]=add(mul(m[k+1][0],2),m[k][0]);
        m[k+1][1]=add(m[k+1][1],m[k+1][1]);
        if (k==0)
        {
            m[1][0]=add(m[1][0],1);
            ans=add(ans,1);
        }
        if (k==1)
        {
            m[0][1]=add(m[0][1],1);
            ans=add(ans,1);
        }
        // cerr<<"After "<<k<<"\n";
        // for (int i=0;i<4;++i)
        //     cerr<<m[i][0]<<" "<<m[i][1]<<"\n";
    }
    cout<<ans<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}