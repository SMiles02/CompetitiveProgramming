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

const int mod = 998244353;

ll t2(int k)
{
    k+=k;
    if (k>=mod)
        k-=mod;
    return k;
}

void solve()
{
    int n,k,c,ans=1;
    cin>>n>>k;
    int a[n],b[k+1];
    map<int,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=1;i<=k;++i)
    {
        cin>>b[i];
        m[b[i]]=i;
    }
    if (m[a[0]]&&m[a[0]]<m[a[1]])
        ans=0;
    if (m[a[n-1]]&&m[a[n-1]]<m[a[n-2]])
        ans=0;
    for (int i=1;i+1<n;++i)
        if (m[a[i]])
        {
            c=2;
            if (m[a[i]]<m[a[i+1]])
                --c;
            if (m[a[i]]<m[a[i-1]])
                --c;
            if (c==0)
                ans=0;
            if (c==2)
                ans=t2(ans);
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