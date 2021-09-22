//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 2e5+7, MOD = 998244353;
int last[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,cur=1;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        last[a[i]]=i;
    }
    for (int i=1;i<=n;++i)
    {
        if (last[a[i]]==i)
            ans=add(ans,cur);
        cur=add(cur,cur);
        cout<<cur<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}