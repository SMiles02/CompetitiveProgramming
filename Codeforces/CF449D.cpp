#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int sub(int a, int b)
{
    return add(a,mod-b);
}

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int f[1<<20], tp[1<<20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=0;
    cin>>n;
    tp[0]=1;
    for (int i=1;i<(1<<20);++i)
        tp[i]=add(tp[i-1],tp[i-1]);
    while (n--)
    {
        cin>>k;
        ++f[((1<<20)-1)^k];
    }
    for (int j=0;j<20;++j)
        for (int i=0;i<(1<<20);++i)
            if (i&(1<<j))
                f[i]+=f[i^(1<<j)];
    for (int i=0;i<(1<<20);++i)
    {
        if (__builtin_popcount(i)&1)
            ans=sub(ans,sub(tp[f[((1<<20)-1)^i]],1));
        else
            ans=add(ans,sub(tp[f[((1<<20)-1)^i]],1));
    }
    cout<<ans;
    return 0;
}