#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 6e5,mod=1e9+7;
int parent[mn],r[mn],cyc[mn];

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

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    for (int i=1;i<=v;++i)
    {
        parent[i] = i;
        r[i] = 1;
        cyc[i]=0;
    }
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        r[a] += r[b];
        if (cyc[b])
            cyc[a]=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z;
    cin>>n>>m;
    make_set(m);
    vector<int> ans;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (x==1)
        {
            cin>>y;
            if (cyc[find_set(y)])
                continue;
            cyc[find_set(y)]=1;
        }
        else
        {
            cin>>y>>z;
            if (find_set(y)==find_set(z))
                continue;
            if (cyc[find_set(y)]&&cyc[find_set(z)])
                continue;
            union_sets(y,z);
        }
        ans.push_back(i);
    }
    cout<<binpow(2,sz(ans))<<" "<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}