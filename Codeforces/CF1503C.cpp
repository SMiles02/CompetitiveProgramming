#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=0;
    long long ans=0;
    cin>>n;
    vector<array<int,2>> a(n);
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        ans+=a[i][1];
    }
    sort(a.begin(), a.end());
    for (int i=1;i<n;++i)
    {
        x=max(a[i-1][0]+a[i-1][1],x);
        ans+=max(a[i][0]-x,0);
    }
    cout<<ans;
    return 0;
}