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

int n;
string s;

void check(int a, int b, int c, int d)
{
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    return;
    int x=0,y=0;
    for (int i=a-1;i<b;++i)
    {
        x*=2;
        x+=(s[i]-'0');
    }
    for (int i=c-1;i<d;++i)
    {
        y*=2;
        y+=(s[i]-'0');
    }
    if (x==0&&y==0)
        return;
    if (y==0||x%y)
    {
        cout<<"Error with "<<s<<"\n";
    }
}

void solve()
{
    cin>>n;
    cin>>s;
    for (int i=(n-2)/2;i+1<n;++i)
        if (s[i+1]=='0')
        {
            check(1,i+2,1,i+1);
            return;
        }
    for (int i=0;n-i-1>=n/2;++i)
        if (s[i]=='0')
        {
            check(i+1,n,i+2,n);
            return;
        }
    check(1,n-1,2,n);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}