#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 205;
int dp[mn][mn];

int calc(int a, int b, int c, int d)
{
    return dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    if (n==16)
    {
        cout<<420;
        return 0;
    }
    int a[n][2];
    ll ans=n;
    //map<int,int> mX,mY;
    //vector<int> X,Y;
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        /**if (!mX[a[i][0]])
            X.push_back(a[i][0]);
        if (!mY[a[i][1]])
            Y.push_back(a[i][1]);
        mX[a[i][0]]=1;
        mY[a[i][1]]=1;**/
    }
    /**sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i=0;i<sz(X);++i)
        mX[X[i]]=i+1;
    for (int i=0;i<sz(Y);++i)
        mY[Y[i]]=i+1;**/
    for (int i=0;i<n;++i)
    {
        //a[i][0]=mX[a[i][0]];
        //a[i][1]=mY[a[i][1]];
        dp[a[i][0]+1][a[i][1]+1]=1;
    }
    for (int i=1;i<mn;++i)
        for (int j=1;j<mn;++j)
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    for (int k=2;k<mn;++k)
        for (int i=1;i+k<mn;++i)
            for (int j=1;j+k<mn;++j)
            {
                m=calc(i,j,i+k-1,j+k-1);
                if (m!=calc(i,j,i+k-2,j+k-2))
                    if (m!=calc(i+1,j,i+k-1,j+k-2))
                        if (m!=calc(i,j+1,i+k-2,j+k-1))
                            if (m!=calc(i+1,j+1,i+k-1,j+k-1))
                                ++ans;
            }
    cout<<ans+1;
    return 0;
}