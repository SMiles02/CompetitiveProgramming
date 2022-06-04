#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const ll INF = 1e18;
ll d[800][800];
int id[200001];
bitset<200001> b;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,K,h;
    cin>>n>>m>>h;
    K=min(h,m);
    vector<pair<int,pii>> v(m);
    vector<int> w;
    vector<ll> l;
    for (int i=0;i<m;++i)
        cin>>v[i].s.f>>v[i].s.s>>v[i].f;
    sort(v.begin(), v.end());
    for (int i=0;i<K;++i)
    {
        if (!b[v[i].s.f])
        {
            w.push_back(v[i].s.f);
            b[v[i].s.f]=1;
        }
        if (!b[v[i].s.s])
        {
            w.push_back(v[i].s.s);
            b[v[i].s.s]=1;
        }
    }
    sort(w.begin(), w.end());
    K=sz(w);
    for (int i=0;i<K;++i)
        id[w[i]]=i;
    for (int i=0;i<K;++i)
        for (int j=0;j<K;++j)
            d[i][j]=INF;
    for (int i=0;i<min(h,m);++i)
    {
        d[id[v[i].s.f]][id[v[i].s.s]]=v[i].f;
        d[id[v[i].s.s]][id[v[i].s.f]]=v[i].f;
    }
    for (int k=0;k<K;++k)
        for (int i=0;i<K;++i)
            for (int j=0;j<K;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for (int i=0;i<K;++i)
        for (int j=i+1;j<K;++j)
            if (d[i][j]^INF)
                l.push_back(d[i][j]);
    sort(l.begin(), l.end());
    cout<<l[h-1];
    return 0;
}