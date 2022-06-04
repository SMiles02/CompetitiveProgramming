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

const int N = 3e5+6;
int p[2][N];

void solve()
{
    int n,q,l,r;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> v(n);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='+')
            v[i]=1;
        else
            v[i]=-1;
    }
    for (int i=1;i<=n;++i)
    {
        if (i&1)
            p[1][i]=p[1][i-1]+v[i-1];
        else
            p[1][i]=p[1][i-1]-v[i-1];
    }
    for (int i=1;i<=n;++i)
    {
        if (i&1)
            p[0][i]=p[0][i-1]-v[i-1];
        else
            p[0][i]=p[0][i-1]+v[i-1];
    }
    // for (int i=1;i<=n;++i)
    //     cout<<p[0][i]<<" ";
    // cout<<"\n";
    // for (int i=1;i<=n;++i)
    //     cout<<p[1][i]<<" ";
    // cout<<"\n";
    while (q--)
    {
        cin>>l>>r;
        if ((l&1)==(r&1))
            cout<<"1\n";
        else if (p[l&1][r]-p[l&1][l-1])
            cout<<"2\n";
        else
            cout<<"0\n";
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