#include <bits/stdc++.h>
using namespace std;

//998244353
const int MOD = , N = 2e5+1;
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
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<N;++i)
        f[i]=mul(f[i-1],i);
    return 0;
}