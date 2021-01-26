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

const int mn = 1e5+5, lg = 19, INF=1e9;
int r[lg][mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,q,k,x,y,ans;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>l;
    k=n;
    for (int i=0;i<lg;++i)
        r[i][n]=r[i][n+1]=n+1;
    for (int i=n-1;i;--i)
    {
        while (a[k]-a[i]>l)
            --k;
        r[0][i]=k;
        for (int j=1;j<lg;++j)
            r[j][i]=r[j-1][r[j-1][i]];
    }
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        ans=0;
        if (x>y)
            swap(x,y);
        for (int i=lg-1;i>=0;--i)
            if (r[i][x]<=y)
            {
                ans+=(1<<i);
                x=r[i][x];
            }
        if (x!=y)
            ++ans;
        cout<<ans<<"\n";
    }
    return 0;
}