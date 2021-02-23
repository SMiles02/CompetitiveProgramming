#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,cur=10,w;
string s,t;
bitset<10> dp[200001][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    cin>>t;
    dp[n][0][0]=1;
    for (int i=n-1;i>=0;--i)
    {
        if (t[i]=='*')
        {
            for (int j=(s[i]-'0');j<10;++j)
                for (int k=0;k<10;++k)
                    dp[i][2][j]|=dp[i+1][1][k];
            for (int j=1+(s[i]-'0');j<10;++j)
                for (int k=0;k<10;++k)
                    dp[i][1][j]|=dp[i+1][0][k]|dp[i+1][1][k];
            for (int j=0;j<10;++j)
                for (int k=0;k<10;++k)
                    dp[i][0][j]|=(dp[i+1][0][k]|dp[i+1][1][k]|dp[i+1][2][k]);
        }
        else
        {
            if (t[i]>=s[i])
            {
                for (int k=0;k<10;++k)
                    dp[i][2][t[i]-'0']|=dp[i+1][1][k]|dp[i+1][2][k];
            }
            if (t[i]>s[i])
            {
                for (int k=0;k<10;++k)
                    dp[i][1][t[i]-'0']|=dp[i+1][0][k]|dp[i+1][1][k]|dp[i+1][2][k];
            }
            for (int k=0;k<10;++k)
                dp[i][0][t[i]-'0']|=dp[i+1][0][k]|dp[i+1][1][k]|dp[i+1][2][k];
        }
    }
    for (int i=9;i>=0;--i)
    {
        if (dp[0][2][i])
        {
            cur=i;
            w=2;
        }
        if (dp[0][1][i])
        {
            cur=i;
            w=1;
        }
    }
    if (cur=10)
    {
        cout<<-1;
        return 0;
    }
    for (int i=0;i<n;++i)
    {
        cout<<cur;
        if (w==2)
        {
            for (int k=0;k<10;++k)
                for (int j=1;j<3;++j)
                    if (dp[i+1][j][k])
                    {
                        w=j;
                        cur=k;
                    }
        }
        else if (w==1)
        {
            for (int k=0;k<10;++k)
                for (int j=0;j<2;++j)
                    if (dp[i+1][j][k])
                    {
                        w=j;
                        cur=k;
                    }
        }
        else
        {
            for (int k=0;k<10;++k)
                for (int j=0;j<1;++j)
                    if (dp[i+1][j][k])
                    {
                        w=j;
                        cur=k;
                    }
        }
    }
    return 0;
}