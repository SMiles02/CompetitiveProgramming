#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2") 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e6+7;
int MOD, dp[N];

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
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cur=0, x, y, z, k;
    cin>>n>>MOD;
    dp[n]=1;
    for (int i=n;i>1;--i)
    {
        z=add(dp[i],cur);
        cur=add(cur,z);
        for (x=2;x*x<=i;++x)
            dp[i/x]=add(dp[i/x],z);
        while (x<=i)
        {
            k=i/x;
            y=i/k;
            dp[k]=add(dp[k],mul(z,y-x+1));
            x=y+1;
        }
    }
    cout<<add(dp[1],cur);
    return 0;
}