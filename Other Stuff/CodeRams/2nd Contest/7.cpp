#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll dp[2][130][4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x=-1,y;
    cin>>n>>k;
    vector<int> div(128);
    map<int,int> pToNum;
    for (int i=1;i<=k;++i)
        if (k%i==0)
        {
            div[++x]=i;
            pToNum[i]=x;
        }
    dp[0][0][0]=1;
    while (n--)
    {
        cin>>y;
        if (k%y)
            continue;
        for (int i=0;i<=x;++i)
            if (div[i]%y==0)
                for (int j=1;j<4;++j)
                    dp[1][i][j]=dp[0][pToNum[div[i]/y]][j-1];
        for (int i=0;i<=x;++i)
            for (int j=0;j<4;++j)
            {
                dp[0][i][j]+=dp[1][i][j];
                dp[1][i][j]=0;
            }
    }
    cout<<dp[0][x][3];
    return 0;
}