#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NUM=200000,C=314159265;
int ttt=0,n;
vector<int> edges[NUM+1];
vector<pair<int,int>> p;
bool done[NUM+1];
bool ans[NUM+1];

bool check()
{
    int cor=0;
    p.clear();
    for (int i=1;i<=n;++i)
        p.push_back({uniform_int_distribution<int>(1,(C/sz(edges[i])))(rng),i});
    sort(p.begin(), p.end());
    for (auto j : p)
    {
        if (done[j.second])
            continue;
        ++cor;
        done[j.second]=1;
        ans[j.second]=1;
        for (int i : edges[j.second])
            done[i]=1;
    }
    if (cor>31500)
    {
        cout<<cor<<"\n";
        for (int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        return 1;
    }
    ttt=max(ttt,cor);
    for (int i=1;i<=n;++i)
    {
        ans[i]=0;
        done[i]=0;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,a,b,dd=2000;
    freopen("b3.in", "r", stdin);
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    while (dd--)
        if (check())
            return 0;
    cout<<"You got nothing...\n";
    cout<<"Only "<<ttt;
    return 0;
}