#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
using namespace std;

vector<pair<int,int>> edges[100001];
bool done[100001];
int mini[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,s,l,u,v,w;
    double d;
    cin>>n>>m>>s;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    cin>>l;
    for (int i=1;i<=n;++i)
        mini[i]=1000000000;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    mini[s]=0;
    while (!q.empty())
    {
        u=q.top().first;v=q.top().second;
        q.pop();
        if (done[v])
            continue;
        //cout<<v<<" "<<u<<"\n";
        done[v]=1;
        for (auto p : edges[v])
            if (u+p.second<mini[p.first])
            {
                mini[p.first]=u+p.second;
                q.push({mini[p.first],p.first});
            }
    }
    int ans=0;
    for (int i=1;i<=n;++i)
        for (auto p : edges[i])
        {
            u=min(mini[i],mini[p.first]);
            v=max(mini[i],mini[p.first]);
            if (u+p.second<=v)
            {
                if (u<l&&l<v)
                    ++ans;
            }
            else
            {
                if (u<l&&l<=v)
                    ++ans;
                d=p.second-v+u;
                d/=2;
                //cout<<i<<" "<<p.first<<" "<<d<<" "<<d+v<<"\n";
                if (v<l&&l<d+v)
                {
                    //cout<<"done!\n";
                    ans+=2;
                }
                if (l==d+v)
                    ++ans;
            }

        }
    //cout<<ans<<" test\n";
    ans/=2;
    for (int i=1;i<=n;++i)
        if (mini[i]==l)
            ++ans;
    cout<<ans;
    return 0;
}