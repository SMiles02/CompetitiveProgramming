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

int a[300007];

void solve()
{
    int n,m,p=0;
    cin>>n>>m;
    vector<int> v(n,0), ans;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (i>=a[i])
            ++v[i-a[i]];
        else
            ++v[i-a[i]+n];
    }
    for (int i=0;i<n;++i)
        p+=v[i]/2;
    for (int i=0;i<n;++i)
        if (n-v[i]<=)
            ans.push_back(i);
    cout<<sz(ans);
    for (int i : ans)
        cout<<" "<<i;
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