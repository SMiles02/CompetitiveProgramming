#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x=0,y=0;
    cin>>n;
    int a[n];
    vector<array<int,3>> ans;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
    {
        if (a[i-1]>a[i])
            ++x;
        else
            ++y;
    }
    if (y<x)
    {
        ans.push_back({3,n,(1<<30)-1});
        for (int i=0;i<n;++i)
            a[i]^=((1<<30)-1);
        x=y;
    }
    for (int i=1;i<n;++i)
        if (a[i-1]>a[i])
            ans.push_back({2,i+1,a[i-1]-a[i]});
    cout<<sz(ans)<<"\n";
    for (auto i : ans)
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
}   

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}