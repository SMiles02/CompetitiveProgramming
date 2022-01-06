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
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    t=s;
    sort(t.begin(), t.end());
    vector<vector<int>> v;
    for (int i=0;i<n;++i)
        if (s[i]!=t[i])
        {
            if (s[i]=='1')
            {
                if (sz(v)==0||(sz(v)>0&&s[v.back().back()]=='0'))
                    v.push_back({});
                v.back().push_back(i);
            }
            else
            {
                if (sz(v)==0)
                    v.push_back({});
                v[0].push_back(i);
            }
        }
    cout<<sz(v)<<"\n";
    for (auto i : v)
    {
        cout<<sz(i)<<" ";
        for (auto j : i)
            cout<<j+1<<" ";
        cout<<"\n";
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}