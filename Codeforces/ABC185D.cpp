#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k=1e9+69,ans=0;
    cin>>n>>m;
    vector<int> v;
    for (int i=1;i<=m;++i)
        cin>>a[i];
    sort(a,a+m+1);
    for (int i=1;i<=m;++i)
        if (a[i]-a[i-1]-1)
        {
            v.push_back(a[i]-a[i-1]-1);
            k=min(k,v.back());
        }
    if (n+1-a[m]-1)
    {
        v.push_back(n+1-a[m]-1);
        k=min(k,v.back());
    }
    for (int i : v)
        ans+=((i+k-1)/k);
    cout<<ans;
    return 0;
}