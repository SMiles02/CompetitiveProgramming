#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1)
    {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }

    int find(int i)
    {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);
        if (i^j)
        {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m1,m2,x,y;
    cin>>n>>m1>>m2;
    DSU d1(n), d2(n);
    while (m1--)
    {
        cin>>x>>y;
        d1.unite(x,y);
    }
    while (m2--)
    {
        cin>>x>>y;
        d2.unite(x,y);
    }
    vector<array<int,2>> v;
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            if (d1.find(i)!=d1.find(j))
                if (d2.find(i)!=d2.find(j))
                {
                    d1.unite(i,j);
                    d2.unite(i,j);
                    v.push_back({i,j});
                }
    cout<<sz(v)<<"\n";
    for (auto i : v)
        cout<<i[0]<<" "<<i[1]<<"\n";
    return 0;
}