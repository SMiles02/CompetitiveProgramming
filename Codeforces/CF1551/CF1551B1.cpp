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

void solve()
{
    int n,k=2,mx=0,val=0,cur=0,extra=0,dn=0,pt=0;
    string s;
    cin>>s;
    n=sz(s);
    vector<int> f(27), g(n+1), p(n+1), ans(n+1);
    vector<vector<int>> v(27);
    for (int i=0;i<n;++i)
    {
        //cout<<s[i]<<" "<<(s[i]-'a')+1<<"\n";
        //continue;
        v[(s[i]-'a')+1].push_back(i);
        ++f[(s[i]-'a')+1];
    }
    //cout<<"ok\n";return;
    for (int i=1;i<=26;++i)
        if (f[i])
            ++g[f[i]];
    for (int i=1;i<=n;++i)
    {
        p[i]=p[i-1]+g[i]*i;
    }
    // for (int i=n;i>0;--i)
    // {
    //     cur+=g[i];
    //     if (mx<(cur+p[i]/i)*i)
    //     {
    //         mx=(cur+p[i]/i)*i;
    //         val=i;
    //         extra=p[i]/i;
    //     }
    // }
    val = 2;
    extra=p[k-1]/k;
    for (int i=1;i<=26;++i)
    {
        if (f[i]>=val)
            for (int j=0;j<val;++j)
            {
                ans[v[i][j]]=j+1;
                ++pt;
            }
        else
            for (int j=0;j<sz(v[i])&&dn<extra;++j)
            {
                ans[v[i][j]]=++cur;
                ++pt;
                if (cur==val)
                {
                    cur=0;
                    ++dn;
                }
            }
    }
    // for (int i=0;i<n;++i)
    //     cout<<ans[i]<<" ";
    // cout<<"\n";
    cout<<pt/2<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}