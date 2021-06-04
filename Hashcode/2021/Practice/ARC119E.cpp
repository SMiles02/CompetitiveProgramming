#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int M = 1e4;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout<<"ok\n";
    return 0;
    int n;
    ll og=0, ans;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
        og+=abs(a[i]-a[i-1]);
    ans=og;
    cout<<ans<<"\n";
    for (int i=1;i<n;++i)
        ans=min({ans,og-abs(a[i]-a[i-1])+abs(a[i]-a[0]),og-abs(a[i]-a[i-1])+abs(a[n-1]-a[i-1])});
    cout<<ans;
    return 0;
}