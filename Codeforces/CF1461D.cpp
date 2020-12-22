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

const ll INF = 1e9;

int a[100001];
ll p[100001];
set<int> s;

void f(int l, int r)
{
    //cout<<l<<" "<<r<<"\n";
    if (p[r]-p[l-1]<=INF)
        s.insert(p[r]-p[l-1]);
    if (a[l]==a[r])
        return;
    int mid=(a[l]+a[r])/2,L=l,R=r,M;
    while (L<R)
    {
        M=L+(R-L)/2+1;
        if (a[M]<=mid)
            L=M;
        else
            R=M-1;
    }
    f(l,L);
    f(L+1,r);
}

void solve()
{
    int n,q,k;
    cin>>n>>q;
    s.clear();
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        p[i]=p[i-1]+a[i];
    f(1,n);
    while (q--)
    {
        cin>>k;
        if (s.find(k)!=s.end())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
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