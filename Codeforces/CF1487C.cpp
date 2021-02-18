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

int a[201][201];

void solve()
{
    int n;
    cin>>n;
    if ((n&1)==0)
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<n/2&&i+j<=n;++j)
                a[i][i+j]=1;
            a[i][i+n/2]=0;
            for (int j=n/2+1;j<n&&i+j<=n;++j)
                a[i][i+j]=-1;
        }
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
                cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    else
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n/2&&i+j<=n;++j)
                cout<<"1 ";
            for (int j=n/2+1;j<n&&i+j<=n;++j)
                cout<<"-1 ";
        }
        cout<<"\n";
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