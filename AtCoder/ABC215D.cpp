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

bitset<100005> f;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m;
    bool ok;
    vector<int> ans;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        for (int j=1;j*j<=k;++j)
            if (k%j==0)
            {
                f[j]=1;
                f[k/j]=1;
            }
    }
    for (int i=1;i<=m;++i)
    {
        k=i;
        ok=1;
        for (int j=2;j*j<=k;++j)
            if (k%j==0)
            {
                ok&=(!f[j]);
                while (k%j==0)
                    k/=j;
            }
        if (k>1)
            ok&=(!f[k]);
        if (ok)
            ans.push_back(i);
    }
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<"\n";
    return 0;
}