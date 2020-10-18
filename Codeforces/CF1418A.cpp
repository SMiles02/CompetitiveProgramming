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

const int INF = 1e9;

void solve()
{
    ll x,y,k,a,l=0,r=16,m;
    cin>>x>>y>>k;
    while (y*k>x*r+1-r||x*r+1-r-y*k<k)
        r*=2;
    while (l<r)
    {
        m=l+(r-l)/2;
        a=x*m+1-m;
        if (y*k>a||a-y*k<k)
        {
            //cout<<m<<" doesnt work\n";
            l=m+1;
        }
        else
        {
            //cout<<m<<" doesnt work\n";
            r=m;
        }
    }
    cout<<l+k<<"\n";
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