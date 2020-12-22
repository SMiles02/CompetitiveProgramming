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
    int n,m,k,r;
    cin>>n>>m;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    k=n;
    for (int i=n;i>=1;--i)
    {
        if (a[i]==i)
            --k;
        else
            break;
    }
    double nS=1,p;
    if (k==0)
    {
        while (m--)
            cin>>r>>p;
        cout<<1<<"\n";
        return;
    }
    while (m--)
    {
        cin>>r;
        cin>>p;
        if (k<=r)
            nS*=(1-p);
    }
    cout<<fixed<<setprecision(10)<<1-nS<<"\n";
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