#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 2e5+1;
int f[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b)
{
    return mul(a,binpow(b,MOD-2));
}

int C(int n, int k)
{
    return dv(f[n],mul(f[k],f[n-k]));
}

int sub(int a, int b)
{
    return add(a,MOD-b);
}

void solve()
{
    int n,x=0,y=0;
    cin>>n;
    int a[n],ans=0;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    if (a[n-1]>a[n-2]+1)
    {
        cout<<"0\n";
        return;
    }
    for (int i=0;i<n;++i)
    {
        if (a[i]==a[n-1])
            ++x;
        if (a[i]+1==a[n-1])
            ++y;
    }
    if (x>1)
    {
        cout<<f[n]<<"\n";
        return;
    }
    for (int i=1;n-i>=y;++i)
        ans=add(ans,sub(f[n-1],mul(f[y],mul(C(n-i,y),f[n-x-y]))));
    for (int i=n-y+1;i<=n;++i)
        ans=add(ans,f[n-1]);
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<N;++i)
        f[i]=mul(f[i-1],i);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}