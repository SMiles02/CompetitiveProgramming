#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans[200000];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x=0,y=0,z=0,k;
    cin>>n>>m;
    int a[n];
    vector<array<int,2>> v(n-1),w(n-1);
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i+1<n;++i)
        v[i]=w[i]={a[i+1]-a[i],i};
    sort(v.rbegin(), v.rend());
    sort(w.rbegin(), w.rend());
    while (m--)
    {
        cin>>k;
        z+=k;
        if (k<0)
        {
            while (!v.empty()&&v.back()[0]<=y-z)
            {
                ans[v.back()[1]+1]+=max(v.back()[0]-y,-x);
                v.pop_back();
            }
        }
        else
        {
            while (!w.empty()&&w.back()[0]<=z-x)
            {
                ans[w.back()[1]]+=max(w.back()[0]+x,y);
                w.pop_back();
            }
        }
        x=min(x,z);
        y=max(y,z);
    }
    for (auto i : v)
        ans[i[1]+1]-=x;
    for (auto i : w)
        ans[i[1]]+=y;
    ans[0]+=-x;
    ans[n-1]+=y;
    for (int i=0;i<n;++i)
        cout<<ans[i]<<"\n";
    return 0;
}