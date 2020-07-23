#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

set<pair<int,ll>> positions;
set<pair<ll,int>> s;

ll smaller(int x)
{
    set<pair<int,ll>>::iterator it;
    if (x==(*(positions.begin())).first)
        it=--(positions.end());
    else
        it=++(positions.begin());
    ll y;
    y=(*it).second;
    s.erase(s.lower_bound({y,(*it).first}));
    positions.erase(it);
    return y;
}

ll bigger(int x)
{
    set<pair<int,ll>>::iterator it;
    if (x==(*(--positions.end())).first)
        it=(positions.begin());
    else
        it=(--positions.end());
    ll y;
    y=(*it).second;
    s.erase(s.lower_bound({y,(*it).first}));
    positions.erase(it);
    return y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    ll y,w;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        positions.insert({i,x});
        s.insert({x,i});
    }
    while (sz(s)>1)
    {
        w=(*(s.begin())).first;
        x=(*(s.begin())).second;
        y=smaller(x)+bigger(x);
        s.erase(s.begin());
        s.insert({y,x});
        positions.erase(positions.lower_bound({x,w}));
        positions.insert({x,y});
    }
    cout<<(*(s.begin())).first;
    return 0;
}