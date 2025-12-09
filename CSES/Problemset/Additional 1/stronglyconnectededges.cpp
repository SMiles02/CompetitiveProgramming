#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+7;
int tin[N], low[N], timer;
vector<int> e[N];
vector<array<int,2>> ans;
bool ok=1;
 
void dfs(int c, int p)
{
    tin[c] = low[c] = ++timer;
    for (int i : e[c])
        if (i!=p)
        {
            if (tin[i])
            {
                low[c]=min(low[c],tin[i]);
                if (tin[i]<tin[c])
                    ans.push_back({c,i});
            }
            else
            {
                dfs(i,c);
                low[c]=min(low[c],low[i]);
                ans.push_back({c,i});
                if (tin[c]<low[i])
                    ok=0;
            }
        }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
        if (!tin[i])
            ok=0;
    if (!ok)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for (auto i : ans)
        cout<<i[0]<<" "<<i[1]<<"\n";
    return 0;
}