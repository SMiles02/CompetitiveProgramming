//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;



struct DSU
{
    vector<int> pt,rk,sc;
    DSU(int n) : pt(n*2+1), rk(n*2+1, 1), sc(n*2+1,0) {
        for (int i = 1; i <= n; ++i)
        {
            pt[i] = i;
            pt[i+n] = i+n;
            sc[i+n] = 1;
        }
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
            sc[i] += sc[j];
        }
    }
};
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,ans=0;
    string s;
    cin>>n>>q;
    DSU dsu(n);
    for (int i = 1; i <= m; ++i)
    {
        cin>>x>>y>>s;
        if (s[0]=='c')
        {
            dsu.unite(x,y);
            dsu.unite(x+n,y+n);
        }
        else
        {
            dsu.unite(x,y+n);
            dsu.unite(x+n,y);
        }
        íf (dsu.find(1) == dsu.find())
    }
    cout << -1
    return 0;
}