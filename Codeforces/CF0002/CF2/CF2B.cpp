#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int maxTwo(int x)
{
    int ans=0;
    while (x%2==0&&x)
    {
        x/=2;
        ++ans;
    }
    return ans;
}

int maxFive(int x)
{
    int ans=0;
    while (x%5==0&&x)
    {
        x/=5;
        ++ans;
    }
    return ans;
}

int n;

void getAns(int dp[][1000], int x, int y)
{
    if (x==0)
    {
        for (int i=0;i<y;++i)
        {
            cout<<"R";
        }
        return;
    }
    if (y==0)
    {
        for (int i=0;i<x;++i)
        {
            cout<<"D";
        }
        return;
    }
    if (dp[x-1][y]<dp[x][y-1])
    {
        getAns(dp,x-1,y);
        cout<<"D";
        return;
    }
    getAns(dp,x,y-1);
    cout<<"R";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int flagX=-1;
    cin>>n;
    int a[n][n];
    int dpTwo[n][1000];
    int dpFive[n][1000];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            cin>>a[i][j];
            if (a[i][j]==0)
            {
                flagX=i;
            }
        }
    }
    dpTwo[0][0]=maxTwo(a[0][0]);
    for (int i=1;i<n;++i)
    {
        dpTwo[i][0]=maxTwo(a[i][0])+dpTwo[i-1][0];
    }
    for (int i=1;i<n;++i)
    {
        dpTwo[0][i]=maxTwo(a[0][i])+dpTwo[0][i-1];
    }
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<n;++j)
        {
            dpTwo[i][j]=maxTwo(a[i][j])+min(dpTwo[i][j-1],dpTwo[i-1][j]);   
        }
    }
    dpFive[0][0]=maxFive(a[0][0]);
    for (int i=1;i<n;++i)
    {
        dpFive[i][0]=maxFive(a[i][0])+dpFive[i-1][0];
    }
    for (int i=1;i<n;++i)
    {
        dpFive[0][i]=maxFive(a[0][i])+dpFive[0][i-1];
    }
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<n;++j)
        {
            dpFive[i][j]=maxFive(a[i][j])+min(dpFive[i][j-1],dpFive[i-1][j]);
        }
    }
    if (flagX>=0&&0<min(dpTwo[n-1][n-1],dpFive[n-1][n-1]))
    {
        cout<<"1\n";
        for (int i=0;i<flagX;++i)
        {
            cout<<'D';
        }
        for (int i=1;i<n;++i)
        {
            cout<<"R";
        }
        for (int i=flagX;i<n-1;++i)
        {
            cout<<'D';
        }
        return 0;
    }
    cout<<min(dpTwo[n-1][n-1],dpFive[n-1][n-1])<<"\n";
    if (dpTwo[n-1][n-1]<dpFive[n-1][n-1])
    {
        getAns(dpTwo,n-1,n-1);
    }
    else
    {
        getAns(dpFive,n-1,n-1);
    }
    return 0;
}