#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 2e6+1;
int d[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL*a*b)%MOD;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y,z,ans=0,cur=1;
    cin>>n>>k;
    x=binpow(2,k+1);
    y=binpow(2,k);
    z=binpow(2,k-1);
    d[k]=add(d[k],x);
    for (int i=1;i<k-i;++i)
        d[k-i]=add(d[k-i],y);
    if ((k&1)==0)
        d[k/2]=add(d[k/2],z);
    for (int i=1;i<N;++i)
        d[i]=add(d[i-1],d[i]);
    for (int i=n-1;i>=0;--i)
    {
        ans=add(ans,mul(cur,d[i]));
        cur=mul(cur,2);
    }
    cout<<ans;
    return 0;
}