#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll ans=0;
    cin>>n;
    priority_queue<pair<int,int>> q;
    int cost[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>cost[i];
        q.push({cost[i],i});
    }
    int positionOf[n+1];
    int whosAt[n+1];
    int ideal[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>whosAt[i];
        positionOf[whosAt[i]]=i;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        ideal[k]=i;
    }
    while (sz(q))
    {
        if (positionOf[q.top().second]==ideal[q.top().second])
        {
            q.pop();
            continue;
        }
        ans+=q.top().first+cost[whosAt[ideal[q.top().second]]];
        cout<<q.top().first<<" "<<cost[whosAt[ideal[q.top().second]]]<<"\n";
        positionOf[whosAt[ideal[q.top().second]]]=positionOf[q.top().second];
        whosAt[positionOf[q.top().second]]=whosAt[ideal[q.top().second]];
        q.pop();
    }
    cout<<ans;
    return 0;
}