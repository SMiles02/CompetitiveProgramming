// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7, N = 2e5+1;
int f[N];

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

int C(int n, int k) { return dv(f[n],mul(f[k],f[n-k])); }

void calc_factorials() {
    f[0]=1;
    for (int i=1;i<N;++i) f[i]=mul(f[i-1],i);
}

int m[31][2];
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n,ans,k;
    cin>>n;
    ans=sub(binpow(2,n),1);
    for (int j=0;j<n;++j)
    {
        cin>>k;
        if ((k&1)==0)
            for (int i=2;i<31;++i)
            {
                if ((k&((1<<i)-1))==0)
                    ++m[i][0];
                else if ((k&((1<<i)-1))==(1<<(i-1)))
                    ++m[i][1];
            }
    }
    for (int i=2;i<31;++i)
        for (int j=1;j<=m[i][1];j+=2)
            ans=sub(ans,mul(C(m[i][1],j),binpow(2,m[i][0])));
    cout<<ans;
    return 0;
}