#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
using namespace std;

vector<pii> v[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>x>>y;
        v[min(x,n+1-y)].push_back({max(x,n+1-y),i+1});
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<int> ans;
    for (int i=1;i<=n;++i)
    {
        for (auto p : v[i])
            q.push({p.first,p.second});
        while (!q.empty())
        {
            if (q.top().first<i)
            {
                q.pop();
                continue;
            }
            ans.push_back(q.top().second);
            q.pop();
            break;
        }
    }
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}