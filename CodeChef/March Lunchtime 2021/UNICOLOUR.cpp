#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a3 array<int,3>
using namespace std;

const int mod = 998244353;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

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

void solve()
{
    int n,m,c,x,y,z,l,r;
    cin>>c>>n>>m;
    DSU dsu(c);
    vector<a3> v,w;
    vector<int> ans(c+1,0);
    for (int i=1;i<=c;++i)
    {
        cin>>x;
        while (x--)
        {
            cin>>y>>z;
            v.push_back({y,z,i});
        }
    }
    sort(v.begin(), v.end());
    l=v[0][0];r=v[0][1];x=v[0][2];
    for (int i=1;i<sz(v);++i)
    {
        if (v[i][0]<=r)
        {
            dsu.unite(x,v[i][2]);
            r=max(r,v[i][1]);
            continue;
        }
        w.push_back({l,r,x});
        l=v[i][0];
        r=v[i][1];
        x=v[i][2];
    }
    w.push_back({l,r,x});
    for (auto i : w)
    {
        //cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
        ans[dsu.find(i[2])]+=i[1]-i[0]+1;
    }
    for (int i=1;i<=c;++i)
        if (dsu.find(i)==i)
        {
            //cout<<i<<": "<<ans[i]<<"\n";
            n-=(ans[i]-1);
        }
    //cout<<"n = "<<n<<"\n";
    cout<<binpow(m,n)<<"\n";
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