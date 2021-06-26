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

bool ok(int a, int b, int c, int d)
{
    if (!(a>=0&&b>=0&&c>=0&&d>=0))
        return 0;
    int o=0;
    for (int x : {a,b,c,d})
        if (x&1)
            ++o;
    if (o>1)
        return 0;
    return 1;
}

void solve()
{
    int r,g,b,w;
    cin>>r>>g>>b>>w;
    if (ok(r,g,b,w)||ok(r-1,g-1,b-1,w+3))
        cout<<"YES\n";
    else
        cout<<"NO\n";
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