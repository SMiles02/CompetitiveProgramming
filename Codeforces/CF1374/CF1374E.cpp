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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y,z;
    ll ans=0;
    cin>>n>>k;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    while (n--)
    {
        cin>>x>>y>>z;
        if (y&&z)
            c.push_back(x);
        else if (y)
            a.push_back(x);
        else if (z)
            b.push_back(x);
    }
    if (sz(a)+sz(c)<k||sz(b)+sz(c)<k)
    {
        cout<<-1;
        return 0;
    }
    sort(c.rbegin(), c.rend());
    sort(b.rbegin(), b.rend());
    sort(a.rbegin(), a.rend());
    while (k--)
    {
        if (sz(b)==0||sz(a)==0)
        {
            ans+=c.back();
            c.pop_back();
        }
        else if (sz(c)==0)
        {
            ans+=a.back()+b.back();
            a.pop_back();
            b.pop_back();
        }
        else if (c.back()<a.back()+b.back())
        {
            ans+=c.back();
            c.pop_back();
        }
        else
        {
            ans+=a.back()+b.back();
            a.pop_back();
            b.pop_back();
        }
    }
    cout<<ans;
    return 0;
}