#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

struct DSU
{
    int id;
    vector<int> pt,rk;
    vector<vector<int>> hd;
    DSU(int n, int id) : pt(n+1), rk(n+1, 1), hd(n+1), id(id)
    {
        for (int i = 1; i <= n; ++i)
        {
            pt[i] = i;
            hd[i].push_back(i);
        }
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
            while (!hd[j].empty())
            {
                hd[i].push_back(hd[j].back());
                hd[j].pop_back();
            }
            //cout<<id<<": "<<j<<" -> "<<i<<"\n";
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m1,m2,x,y;
    bool bk;
    cin>>n>>m1>>m2;
    DSU d1(n,1), d2(n,2);
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
    vector<int> heads;
    vector<array<int,2>> v;
    for (int i=1;i<=n;++i)
        if (d1.find(i)==i)
            heads.push_back(i);
    while (!heads.empty())
    {
        x=heads.back();
        heads.pop_back();
        if (d1.find(x)!=x)
            continue;
        //cout<<"x="<<x<<"\n";
        for (int i : heads)
        {
            bk=0;
            if (d1.find(i)==i)
            {
                //cout<<"i="<<i<<"\n";
                for (int j : d1.hd[i])
                {
                    for (int k : d1.hd[x])
                    {
                        //cout<<"trying "<<j<<" "<<k<<" "<<i<<" "<<x<<"\n";
                        if (d2.find(j)!=d2.find(k))
                        {
                            d1.unite(j,k);
                            d2.unite(j,k);
                            v.push_back({j,k});
                            bk=1;
                            break;
                        }
                        //cout<<"nope\n";
                    }
                    if (bk)
                        break;
                }
            }
            if (d1.find(x)!=x)
                break;
        }
        //cout<<"fin\n";
    }
    cout<<sz(v)<<"\n";
    for (auto i : v)
        cout<<i[0]<<" "<<i[1]<<"\n";
    return 0;
}