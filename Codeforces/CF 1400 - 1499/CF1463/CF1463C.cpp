#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pll pair<ll,ll>
#define f first
#define s second
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

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

const ll INF = 1e10;

void solve()
{
    int n,c=0,t,ans=0;
    cin>>n;
    pll p[n+1];
    for (int i=0;i<n;++i)
        cin>>p[i].f>>p[i].s;
    p[n].f=INF;p[n].s=0;
    t=p[0].s;
    if (abs(t)<=p[1].f-p[0].f)
        ++ans;
    for (int i=1;i<n;++i)
    {
        if (c<=t)
            c=min(t,c+p[i].f-p[i-1].f);
        else
            c=max(t,c-p[i].f+p[i-1].f);
        if (c==t)
            t=p[i].s;
        if (c<=t)
        {
            if (c<=p[i].s&&p[i].s<=min(t,c+p[i+1].f-p[i].f))
                ++ans;
        }
        else
        {
            if (max(t,c-p[i+1].f+p[i].f)<=p[i].s&&p[i].s<=c)
                ++ans;
        }
    }
    cout<<ans<<"\n";
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