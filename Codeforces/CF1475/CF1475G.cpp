#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
vector<int> factors[mn];

void factorBuild()
{
    for (int i=1;i<mn;++i)
        for (int j=i;j<mn;j+=i)
            factors[j].push_back(i);
}

int mx[mn];

void solve()
{
    int n,k,ans=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<mn;++i)
        mx[i]=0;
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        k=0;
        for (int j : factors[a[i]])
            k=max(k,mx[j]);
        mx[a[i]]=k+1;
        ans=max(ans,k+1);
    }
    cout<<n-ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    factorBuild();
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}