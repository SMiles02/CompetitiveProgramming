#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,m=0,x;
    map<int,int> dp;
    map<int,vector<pair<int,int>>> start;
    cin>>n;
    pair<int,int> p[n];
    set<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>p[i].first>>p[i].second;
        s.insert(p[i].first);
        s.insert(p[i].second);
        s.insert(p[i].first-1);
    }
    for (int i=0;i<n;++i)
    {
        x=1;
        for (int j=0;j<i;++j)
            if (p[i].first<=p[j].first&&p[j].second<=p[i].second)
                ++x;
        for (int j=i+1;j<n;++j)
            if (p[i].first<=p[j].first&&p[j].second<=p[i].second)
                ++x;
        cout<<i<<": "<<x<<"\n";
        start[p[i].second].push_back({p[i].first-1,x});
    }
    for (int i : s)
    {
        x=0;
        for (auto j : start[i])
            x=max(x,j.second+dp[j.first]);
        m=max(m,x);
        dp[i]=m;
        cout<<"dp["<<i<<"] = "<<dp[i]<<"\n";
    }
    cout<<m<<"\n";
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