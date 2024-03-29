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
    string s;
    cin>>s;
    for (int i=1;i<n;++i)
        if (s[i-1]!='?'&&s[i]=='?')
        {
            if (s[i-1]=='R')
                s[i]='B';
            else
                s[i]='R';
        }
    for (int i=n-1;i>=0;--i)
        if (s[i+1]!='?'&&s[i]=='?')
        {
            if (s[i+1]=='R')
                s[i]='B';
            else
                s[i]='R';
        }
    if (s[0]=='?')
        s[0]='R';
    for (int i=1;i<n;++i)
        if (s[i-1]!='?'&&s[i]=='?')
        {
            if (s[i-1]=='R')
                s[i]='B';
            else
                s[i]='R';
        }
    cout<<s<<"\n";
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