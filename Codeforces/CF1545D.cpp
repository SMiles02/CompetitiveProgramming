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
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,k,x=-1;
    cin>>m>>k;
    vector<vector<int>> v(k, vector<int>(m));
    for (int i=0;i<k;++i)
        sort(v[i].begin(), v[i].end());
    for (int i=0;i<m;++i)
    {
        set<int> s;
        map<int,int> mp;
        for (int j=1;j<k;++k)
        {
            s.insert(v[j][i]-v[j-1][i]);
            ++mp[v[j][i]-v[j-1][i]];
        }
        if (s.size()==1)
            continue;
        vector<array<int,2>> w;
        for (auto i : mp)
            w.push_back({i.s,i.f});
        sort(w.begin(), w.end());
        x=-1;
        for (int j=1;j+1<k;++j)
            if (v[j][i]-v[j-1][i]!=w.back()[1]&&v[j+1][i]-v[j][i]!=w.back()[1])
                x=j;
        if (x!=-1)
        {
            if (i+1==m)
            {
                cout<<
            }
        }
    }
    return 0;
}