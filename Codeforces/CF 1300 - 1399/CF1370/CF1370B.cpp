#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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
    int n,x;
    cin>>n;
    vector<int> e;
    vector<int> o;
    for (int i=0;i<2*n;++i)
    {
        cin>>x;
        if (x&1)
            o.push_back(i+1);
        else
            e.push_back(i+1);
    }
    --n;
    while (n--)
    {
        if (sz(e)>2)
        {
            cout<<e.back()<<" ";
            e.pop_back();
            cout<<e.back()<<"\n";
            e.pop_back();
        }
        else
        {
            cout<<o.back()<<" ";
            o.pop_back();
            cout<<o.back()<<"\n";
            o.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}