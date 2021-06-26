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
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    vector<int> ans1;
    vector<int> ans2;
    char c=s[0],d=t[0];
    for (int i=1;i<n;++i)
    {
        if (s[i]!=c)
            ans1.push_back(i);
        c=s[i];
    }
    for (int i=1;i<n;++i)
    {
        if (t[i]!=d)
            ans2.push_back(i);
        d=t[i];
    }
    if (c!=d)
        ans1.push_back(n);
    for (int i=sz(ans2)-1;i+1;--i)
        ans1.push_back(ans2[i]);
    cout<<sz(ans1)<<" ";
    for (int i : ans1)
        cout<<i<<" ";
    cout<<"\n";
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