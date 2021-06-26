#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k,x,ans;
    cin>>n>>k>>x;
    ll a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    vector<ll> v(n-1);
    for (int i=1;i<n;++i)
        v[i-1]=max(a[i]-a[i-1]-1,0LL)/x;
    sort(v.begin(), v.end());
    ans=n;
    for (auto i : v)
        if (k-i>=0)
        {
            k-=i;
            --ans;
        }
    cout<<ans;
    return 0;
}