#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[5000],INF=1e9+2;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll dp(int l, int r, int h)
{
    if (l==r)
    {
        if (a[l]==0)
            return 0;
        return 1;
    }
    if (r<l)
        return 0;
    ll ans=0;
    int m=INF;
    vector<int> v;
    for (int i=l;i<=r;++i)
    {
        if (a[i]<m)
        {
            v.clear();
            m=a[i];
        }
        if (a[i]==m)
            v.push_back(i);
    }
    ans=(m-h);
    for (int i=0;i+1<sz(v);++i)
        ans+=dp(v[i]+1,v[i+1]-1,m);
    if (v[0]!=l)
        ans+=dp(l,v[0]-1,m);
    if (v.back()!=r)
        ans+=dp(v.back()+1,r,m);
    return min(ans,r-l+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    cout<<dp(0,n-1,0);
    return 0;
}