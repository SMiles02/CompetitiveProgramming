#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,ans=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        ans+=abs(a[i]-i-1);
    }
    cout<<ans;
    return 0;
}