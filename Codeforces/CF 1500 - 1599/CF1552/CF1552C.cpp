#include <bits/stdc++.h>
using namespace std;

int btwn(int x, int y, int z)
{
    return (x<z&&z<y);
}

bitset<201> b;

void solve()
{
    int n,k,m,x,y,ans=0;
    cin>>n>>k;
    m=n-k;
    b.reset();
    vector<int> v;
    vector<array<int,2>> w;
    while (k--)
    {
        cin>>x>>y;
        if (y<x)
            swap(x,y);
        w.push_back({x,y});
        b[x]=b[y]=1;
    }
    for (int i=1;i<=n*2;++i)
        if (!b[i])
            v.push_back(i);
    for (int i=0;i<m;++i)
        w.push_back({v[i],v[i+m]});
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
            ans += ((btwn(w[i][0],w[i][1],w[j][0])&&!btwn(w[i][0],w[i][1],w[j][1]))||(btwn(w[i][0],w[i][1],w[j][1])&&!btwn(w[i][0],w[i][1],w[j][0])));
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}