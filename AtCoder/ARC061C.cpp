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

int n;
string s;

ll f(int l, int r)
{
    ll x=0;
    for (int i=l;i<=r;++i)
    {
        x*=10;
        x+=(s[i]-'0');
    }
    return x;
}

ll ans;

void rec(bitset<10> b, int l, int c, ll s)
{
    if (c==n-1)
    {
        s+=f(l+1,c);
        ans+=s;
        return;
    }
    rec(b,l,c+1,s);
    s+=f(l+1,c);
    b[c]=1;
    l=c;
    rec(b,l,c+1,s);
} 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    n=sz(s);
    bitset<10> b;
    rec(b,-1,0,0);
    cout<<ans;
    return 0;
}