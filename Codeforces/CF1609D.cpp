// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ex;
multiset<int, greater<int>> s;

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1) {
        for (int i = 1; i <= n; ++i)
        {
            s.insert(1);
            pt[i] = i;
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
            s.erase(s.lower_bound(rk[i]));
            s.erase(s.lower_bound(rk[j]));
            rk[i] += rk[j];
            s.insert(rk[i]);
        }
        else
            ++ex;
    }
};
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,d,x,y,ans;
    cin>>n>>d;
    DSU dsu(n);
    while (d--)
    {
        cin>>x>>y;
        dsu.unite(x,y);
        vector<int> v;
        ans=0;
        for (int i=0;i<=ex;++i)
        {
            v.push_back(*s.begin());
            s.erase(s.begin());
            ans+=v.back();
        }
        cout<<ans-1<<"\n";
        for (int i : v)
            s.insert(i);
    }
    return 0;
}