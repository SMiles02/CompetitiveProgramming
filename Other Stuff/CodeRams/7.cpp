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

const int INF = 64e6;

int p[401][401], a[401][401], dp[2][2][401][401];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=-INF;
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            p[i][j]=a[i][j]+p[i][j-1];
        }
    for (int j=1;j<=n;++j)
        for (int k=j+2;k<=n;++k)
        {
            dp[0][0][j][k]=p[1][k]-p[1][j-1];
            dp[0][1][j][k]=-INF;
        }
    //old/new, first/notfirst, j, k
    for (int i=2;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            for (int k=j+2;k<=n;++k)
            {
                dp[1][0][j][k]=p[i][k]-p[i][j-1];
                dp[1][1][j][k]=max(dp[0][0][j][k],dp[0][1][j][k])+a[i][j]+a[i][k];
                ans=max(ans,dp[0][1][j][k]+p[i][k]-p[i][j-1]);
            }
        for (int t=0;t<2;++t)
            for (int j=1;j<=n;++j)
                for (int k=j+2;k<=n;++k)
                    dp[0][t][j][k]=dp[1][t][j][k];
    }
    cout<<ans;
    return 0;
}