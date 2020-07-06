#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

int dp[201][20001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,INF=1e9,cur;
    cin>>n;
    int b[n+1];
    int c[n+1];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=n;++i)
        cin>>c[i];
    cin>>k;
    for (int i=0;i<201;++i)
        for (int j=0;j<20001;++j)
            dp[i][j]=INF;
    dp[0][0]=0;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=k;++j)
        {
            for (int l=0;l<=c[i]&&l*b[i]<=j;++l)
                dp[i][j]=min(dp[i][j],dp[i-1][j-l*b[i]]+l);
        }
    cout<<dp[n][k]<<"\n";
    int ans[n+1];
    cur=k;
    for (int i=n;i;--i)
    {
        //cout<<cur<<"\n";
        for (int j=0;j<20001;++j)
            if (dp[i][cur]-j==dp[i-1][cur-j*b[i]])
            {
                ans[i]=j;
                cur-=j*b[i];
                break;
            }
    }
    /**for (int i=0;i<4;++i)
    {
        for (int j=0;j<=k;++j)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }**/
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}