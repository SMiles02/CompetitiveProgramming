#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5;
int a[N][4];
ll dp[8001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<4;++i)
        for (int j=0;j<n;++j)
            cin>>a[j][i];
    for (int i=1;i<=4000;++i)
    {
        dp[i]=max(dp[i-1],dp[i]);
        for (int j=0;j<n;++j)
            if (a[j][0]<=i&&i<=a[j][0]+a[j][2])
                dp[i+a[j][1]]=max(dp[i+a[j][1]],dp[i]+a[j][3]);
    }
    for (int i=4001;i<=8000;++i)
        dp[i]=max(dp[i-1],dp[i]);
    cout<<dp[8000];
    return 0;
}