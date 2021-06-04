#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[101][101][1001][4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l;
    cin>>n>>l;
    if (n==1)
    {
        cout<<0;
        return 0;
    }
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    dp[0][1][0][0]=1;
    dp[0][1][]
    return 0;
}