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

int a[10],b[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans1=0,ans2=0,x;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    bool ok;
    for (auto c : t)
    {
        ++a[c-'0'];
        ++b[c-'0'];
    }
    for (auto c : s)
    {
        ok=0;
        for (int i=(c-'0');i<10;++i)
        {
            if (ok)
                continue;
            if (a[i]>0)
            {
                ok=1;
                x=i;
                --a[i];
            }
        }
        for (int i=0;i<10;++i)
        {
            if (ok)
                continue;
            if (a[i]>0)
            {
                ok=1;
                x=i;
                --a[i];
            }
        }
        if (x<(c-'0'))
            ++ans1;
    }
    for (auto c : s)
    {
        ok=0;
        for (int i=(c-'0')+1;i<10;++i)
        {
            if (ok)
                continue;
            if (b[i]>0)
            {
                ok=1;
                x=i;
                --b[i];
            }
        }
        for (int i=0;i<10;++i)
        {
            if (ok)
                continue;
            if (b[i]>0)
            {
                ok=1;
                x=i;
                --b[i];
            }
        }
        if (x>(c-'0'))
            ++ans2;
    }
    cout<<ans1<<"\n"<<ans2;
    return 0;
}