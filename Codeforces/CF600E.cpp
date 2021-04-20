#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define f first
#define s second
using namespace std;

const int mn = 1e5+1;
vector<int> edges[mn];
int col[mn];
ll ans[mn];

struct info
{
    map<int,int> ct;
    map<int,ll> sum;
};

info dfs(int c, int p)
{
    info cur;
    cur.ct[col[c]]=1;
    cur.sum[1]=col[c];
    for (int i : edges[c])
        if (i!=p)
        {
            info tp = dfs(i,c);
            if (tp.ct.size()>cur.ct.size())
                swap(tp,cur);
            for (auto j : tp.ct)
            {
                if (!cur.ct[j.f])
                {
                    cur.ct[j.f]=j.s;
                    cur.sum[j.s]+=j.f;
                }
                else
                {
                    cur.sum[cur.ct[j.f]]-=j.f;
                    cur.ct[j.f]+=j.s;
                    cur.sum[cur.ct[j.f]]+=j.f;
                }
            }
        }
    ans[c] = cur.sum.rbegin()->s;
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>col[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}