#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 998244353;
int dp[1500][3];

int dub(int x)
{
    x+=x;
    if (x>=mod)
        x-=mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='.')
                ++dp[i+j][0];
            else if (s[i][j]=='R')
                ++dp[i+j][1];
            else
                ++dp[i+j][2];
        }
    int ans=1;
    for (int i=0;i<n+m-1;++i)
    {
        if (dp[i][1]>0&&dp[i][2]>0)
            ans=0;
        else if (dp[i][1]==0&&dp[i][2]==0)
            ans=dub(ans);
    }
    cout<<ans;
    return 0;
}