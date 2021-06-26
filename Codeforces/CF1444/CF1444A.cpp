#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
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

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

const ll INF = 1e18;

void solve()
{
    ll p,q,r,ans=INF,cur;
    cin>>p>>q;
    r=p;
    vector<pii> v;
    for (int i=2;i*i<=q;++i)
        if (q%i==0)
        {
            v.push_back({i,0});
            while (q%i==0)
            {
                q/=i;
                ++v.back().s;
            }
        }
    if (q>1)
        v.push_back({q,1});
    for (pii i : v)
    {
        cur=0;
        while (p%i.f==0)
        {
            ++cur;
            p/=i.f;
        }
        //cout<<i.f<<" "<<cur<<" "<<i.s<<"\n";
        if (cur<i.s)
            ans=1;
        else
            ans=min(ans,binpow(i.f,max(0,cur-i.s+1)));
    }
    cout<<r/ans<<"\n";
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