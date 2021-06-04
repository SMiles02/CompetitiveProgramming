#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7;
int dp[N], c[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,l,r,mid,ans=0;
    cin>>n>>m;
    vector<array<int,2>> a(n);
    for (int i=0;i<n;++i)
        cin>>a[i][0]>>a[i][1];
    sort(a.rbegin(), a.rend());
    for (int i=m;i;--i)
        cin>>c[i];
    for (int i=2;i<=n)
        c[i]=min(c[i-1],c[i]);
    for (int i=0;i<n;++i)
    {
        l=0;r=ans;
        while (l<r)
        {
            mid=l+(r-l)/2;
        }
    }
    return 0;
}