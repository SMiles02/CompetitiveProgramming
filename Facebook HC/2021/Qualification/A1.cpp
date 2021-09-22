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

bitset<26> v;

void solve()
{
    string s;
    cin>>s;
    int ans=sz(s)*2,cur;
    for (char c='A';c<='Z';++c)
    {
        cur=0;
        for (auto i : s)
        {
            if (i==c)
                continue;
            if (v[c-'A']==v[i-'A'])
                cur+=2;
            else
                ++cur;
        }
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    v['A'-'A']=1;
    v['E'-'A']=1;
    v['I'-'A']=1;
    v['O'-'A']=1;
    v['U'-'A']=1;
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}