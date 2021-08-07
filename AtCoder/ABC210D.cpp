#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1000][1000];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll c, ans=1e18;
    cin>>n>>m>>c;
    vector<array<int,3>> v;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            cin>>a[i][j];
            v.push_back({a[i][j],i,j});
        }
    sort(v.begin(), v.end());
    for (int i=0;i<min(5000,n*m);++i)
        for (int j=0;j<i;++j)
            ans=min(ans,c*(abs(v[i][1]-v[j][1])+abs(v[i][2]-v[j][2]))+v[i][0]+v[j][0]);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            for (int k=max(0,i-10);k<min(n,i+11);++k)
                for (int l=max(0,j-10);l<min(m,j+11);++l)
                    if (!(i==k&&j==l))
                        ans=min(ans,c*(abs(i-k)+abs(j-l))+a[i][j]+a[k][l]);
    cout<<ans;
    return 0;
}