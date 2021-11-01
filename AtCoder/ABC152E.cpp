#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, N = 1e6+1;
int p[N];

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

  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,ans=0,c,l=1;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        x=a[i];
        for (int j=2;j*j<=x;++j)
        {
            c=0;
            while (x%j==0)
            {
                x/=j;
                ++c;
            }
            p[j]=max(p[j],c);
        }
        p[x]=max(p[x],1);
    }
    for (int i=2;i<N;++i)
        if (p[i])
            l=mul(l,binpow(i,p[i]));
    for (int i=0;i<n;++i)
        ans=add(ans,dv(l,a[i]));
    cout<<ans;
    return 0;
}