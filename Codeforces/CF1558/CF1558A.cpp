  
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

set<int> s;

void check(int x, int y)
{
    int a,b,c,d;
    a=min((x+y+1)/2,x);
    b=(x+y+1)/2-a;
    d=min((x+y)/2,y);
    c=(x+y)/2-d;
    s.insert(b+c);
    while (a--&&d--)
    {
        ++b;
        ++c;
        s.insert(b+c);
    }
}

void solve()
{
    int a,b;
    cin>>a>>b;
    s.clear();
    check(a,b);
    check(b,a);
    cout<<sz(s)<<"\n";
    for (int i : s)
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