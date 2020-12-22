#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    map<int,int> x,y;
    map<pair<int,int>,int> z;
    ll ans = ((ll)n*((ll)n-1))/2;
    for (int i=0;i<n;++i)
    {
        ans+=z[{a[i],b[i]}]-x[a[i]]-y[b[i]];
        ++z[{a[i],b[i]}];
        ++x[a[i]];
        ++y[b[i]];
    }
    cout<<ans;
    return 0;
}