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

bool ok(int x, int y)
{
    if (x>=0&&y>=0)
        return 1;
    return 0;
}

int dp[1005][1005], a[1005], b[1005];

void solve()
{
    int k,n,m;
    cin>>k>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
            dp[i][j]=-1e6;
    dp[0][0]=k;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
        {
            if (i>0)
            {
                if (a[i]==0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                else if (dp[i-1][j]>=a[i])
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
            if (j>0)
            {
                if (b[j]==0)
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                else if (dp[i][j-1]>=b[j])
                    dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
            //cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
        }
    if (dp[n][m]<0)
    {
        cout<<"-1\n";
        return;
    }
    stack<int> s;
    while (n>0||m>0)
    {
        if (n>0&&abs(dp[n][m]-dp[n-1][m])<2)
            s.push(a[n--]);
        else
            s.push(b[m--]);
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
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