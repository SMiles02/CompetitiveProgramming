#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[200001][7];

int sub(int a, int b)
{
    return (((a-b)%7)+7)%7;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c=1;
    cin>>n;
    string s,x;
    cin>>s;
    cin>>x;
    dp[n][0]=1;
    for (int i=n-1;i>=0;--i)
    {
        if (x[i]=='A')
            for (int j=0;j<7;++j)
            {
                if (dp[i+1][j]==0||dp[i+1][sub(j,c*(s[i]-'0'))]==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=1;
            }
        else
            for (int j=0;j<7;++j)
            {
                if (dp[i+1][j]==1||dp[i+1][sub(j,c*(s[i]-'0'))]==1)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
        c=(c*10)%7;
    }
    if (dp[0][0])
        cout<<"Takahashi";
    else
        cout<<"Aoki";
    return 0;
}