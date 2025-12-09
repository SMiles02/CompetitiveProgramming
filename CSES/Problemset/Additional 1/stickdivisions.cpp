#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,n;
    ll ans=0;
    cin>>x>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=n-1;i;--i)
    {
        ans+=x;
        x-=a[i];
    }
    cout<<ans;
    return 0;
}