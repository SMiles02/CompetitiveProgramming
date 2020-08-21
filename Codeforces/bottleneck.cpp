#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int Analyse(int N, int M, int W, int L, int edge_from[], int edge_to[], int capacity[], int R, int C)
{
    pair<int,int> ans[N+1];
    int INF=1e9,x;
    vector<pair<int,int>> edges[N+1];
    queue<int> q;
    R+=C;
    C+=R;
    for (int i=0;i<M;++i)
    {
        edges[edge_from[i]].push_back({edge_to[i],capacity[i]});
        edges[edge_to[i]].push_back({edge_from[i],capacity[i]});
    }
    for (int i=1;i<=N;++i)
        ans[i]={INF,INF};
    q.push(W);
    ans[W]={0,INF};
    while (!q.empty())
    {
        x=q.front();q.pop();
        for (auto j : edges[x])
        {
            if (ans[j.first].first<=ans[x].first)
                continue;
            if (ans[j.first].first==ans[x].first+1)
            {
                ans[j.first].second=min(ans[j.first].second,min(j.second,ans[x].second));
                continue;
            }
            q.push(j.first);
            ans[j.first].second=min(ans[j.first].second,min(j.second,ans[x].second));
            ans[j.first].first=ans[x].first+1;
        }
        cout<<x<<" done\n";
    }
    return ans[L].second;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,w,l,r,c,x,y,z;
    cin>>n>>m>>w>>l>>r>>c;
    int to[m],fro[m],ca[m];
    for (int i=0;i<m;++i)
    {
        cin>>x>>y>>z;
        to[i]=x;
        fro[i]=y;
        ca[i]=z;
    }
    cout<<Analyse(n,m,w,l,to,fro,ca,r,c);
    return 0;
}