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
    int a,b,k;
    cin>>a>>b>>k;
    int c[k][2],f[2][max(a,b)+1];
    vector<int> v[a+1];
    for (int i=0;i<2;++i)
        for (int j=0;j<=max(a,b);++j)
            f[i][j]=0;
    for (int j=0;j<2;++j)
        for (int i=0;i<k;++i)
        {
            cin>>c[i][j];
            ++f[j][c[i][j]];
        }
    for (int i=0;i<k;++i)
        v[c[i][0]].push_back(c[i][1]);
    ll ans=0;
    for (int i=1;i<=a;++i)
        for (int j : v[i])
            ans+=k-f[0][i]-f[1][j]+1;
    cout<<ans/2<<"\n";
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