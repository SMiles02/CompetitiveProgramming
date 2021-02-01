#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int INF = 1e9, maxn = 5e5+7;
int d[maxn],counts[maxn];
vector<int> edges[maxn],finalPos[maxn],range[maxn];
bitset<maxn> done;

void change(int k)
{
    if (done[k])
        return;
    done[k]=1;
    for (int i : finalPos[k])
        --counts[i];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,u,v;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        d[i]=INF;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int a[k];
    queue<int> q;
    for (int i=0;i<k;++i)
    {
        cin>>a[i];
        d[a[i]]=0;
        range[a[i]].push_back(a[i]);
        q.push(a[i]);
    }
    while (!q.empty())
    {
        v=q.front();
        q.pop();
        for (int i : range[v])
            finalPos[i].push_back(v);
        for (int i : edges[v])
            if (d[i]>d[v])
            {
                if (d[i]==INF)
                {
                    d[i]=d[v]+1;
                    q.push(i);
                }
                for (int j : range[v])
                    range[i].push_back(j);
            }
    }
    priority_queue<pii> pq;
    for (int i=1;i<=n;++i)
    {
        counts[i]=sz(range[i]);
        pq.push({counts[i],i});
    }
    vector<int> ans;
    while (!pq.empty())
    {
        u=pq.top().f;
        v=pq.top().s;
        pq.pop();
        if (u>counts[v])
            continue;
        if (u==0)
            break;
        ans.push_back(v);
        for (int i : range[v])
            change(i);
    }
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}