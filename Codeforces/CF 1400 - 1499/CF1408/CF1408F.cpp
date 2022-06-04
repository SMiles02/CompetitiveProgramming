#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

vector<pii> ans;

vector<int> combine(vector<int> &v, vector<int> &w)
{
    vector<int> r;
    for (int i : v)
        r.push_back(i);
    for (int i : w)
        r.push_back(i);
    return r;
}

void break_down(vector<vector<int>> &v)
{
    if (sz(v)==1)
        return;
    vector<vector<int>> w;
    for (int i=0;i<sz(v);i+=2)
    {
        for (int j=0;j<sz(v[i]);++j)
            ans.push_back({v[i][j],v[i+1][j]});
        w.push_back(combine(v[i],v[i+1]));
    }
    break_down(w);
}

void setup(int l, int r)
{
    vector<vector<int>> v;
    for (int i=l;i<=r;++i)
        v.push_back({i});
    break_down(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    m=n;
    while (__builtin_popcount(m)>1)
        m-=(m&-m);
    setup(1,m);
    setup(n-m+1,n);
    cout<<sz(ans)<<"\n";
    for (auto i : ans)
        cout<<i.f<<" "<<i.s<<"\n";
    return 0;
}