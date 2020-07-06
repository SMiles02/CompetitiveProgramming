#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
using pii = pair<int,int>;
 
int n,m,r,g,a,b;
ll ans=-1;
int d[10001];
bool visited[10001][1000];
int done[10001][1000];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i)
        cin>>d[i];
    sort(d+1,d+m+1);
    cin>>g>>r;
    queue<pii> q;
    q.push({0,1});
    while (!q.empty())
    {
        a=q.front().first;
        b=q.front().second;
        q.pop();
        if (b==m)
        {
            if (ans==-1||a<ans)
                ans=a;
            continue;
        }
        if (visited[b][a%g]&&a>=done[b][a%g])
            continue;
        done[b][a%g]=a;
        visited[b][a%g]=1;
        if (b>1&&(a%g)+d[b]-d[b-1]<=g)
            q.push({d[b]-d[b-1]+a,b-1});
        if (b<m&&(a%g)+d[b+1]-d[b]<=g)
            q.push({d[b+1]-d[b]+a,b+1});
    }
    if (ans==-1)
        cout<<-1;
    else if (ans%g)
        cout<<ans+(ans/g)*r;
    else
        cout<<ans+(ans/g-1)*r;
    return 0;
}