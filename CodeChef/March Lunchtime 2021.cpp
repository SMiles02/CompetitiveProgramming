#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1001, mod = 1e9+7;
int dp[N][20];
vector<int> e[N];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

void solve()
{
    int n,m,l,x,y;
    cin>>n>>m>>l;
    string s,t;
    cin>>s;
    cin>>t;
    for (int i=1;i<=n;++i)
    {
        e[i].clear();
        if (t[i-1]==s[0])
            dp[i][0]=1;
        else
            dp[i][0]=0;
    }
    while (m--)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int j=1;j<l;++j)
        for (int i=1;i<=n;++i)
        {
            dp[i][j]=0;
            if (t[i-1]==s[j])
                for (int k : e[i])
                    dp[i][j]=add(dp[i][j],dp[k][j-1]);
        }
    for (int i=2;i<=n;++i)
        dp[i][l-1]=add(dp[i][l-1],dp[i-1][l-1]);
    cout<<dp[n][l-1]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}