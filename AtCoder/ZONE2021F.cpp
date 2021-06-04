#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n), rk(n, 1)
    {
        iota(pt.begin(), pt.end(), 0);
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

bitset<(2<<20)> block,taken;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,b=0,c=0;
    cin>>n>>m;
    DSU dsu(n);
    vector<int> v;
    while (m--)
    {
        cin>>x;
        block[x]=1;
    }
    vector<int> extra(n-1);
    iota(extra.begin(), extra.end(), 1);
    shuffle(extra.begin(), extra.end(), rng);
    for (int i : extra)
        if (((b|i)!=b||(c|((n-1)^i))!=c)&&!block[i])
        {
            v.push_back(i);
            taken[i]=1;
            b|=i;
            c|=((n-1)^i);
        }
    shuffle(extra.begin(), extra.end(), rng);
    for (int i : extra)
        if (sz(v)<1900&&!taken[i]&&!block[i])
            v.push_back(i);
    vector<array<int,2>> ans;
    for (int i=0;i<n;++i)
        for (int j : v)
            if (dsu.find(i)!=dsu.find(i^j))
            {
                dsu.unite(i,i^j);
                ans.push_back({i,i^j});
            }
    if (dsu.rk[0]!=n)
        cout<<-1;
    else
    {
        for (auto i : ans)
            cout<<i[0]<<" "<<i[1]<<"\n";
    }
    return 0;
}