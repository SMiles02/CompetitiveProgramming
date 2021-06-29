#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
const int N = 1e5+7;
int tin[N], low[N], timer;
vector<int> e[N], ans;
 
void dfs(int c, int p)
{
    tin[c] = low[c] = ++timer;
    int cd = 0;
    bool isAP = 0;
    for (int i : e[c])
        if (i!=p)
        {
            if (tin[i])
                low[c]=min(low[c],tin[i]);
            else
            {
                ++cd;
                dfs(i,c);
                low[c]=min(low[c],low[i]);
                if (tin[c]<=low[i])
                    isAP=1;
            }
        }
    if (p==0)
    {
        if (cd>1)
            isAP=1;
        else
            isAP=0;
    }
    if (isAP)
        ans.push_back(c);
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
    for (int i=1;i<=n;++i)
        if (!tin[i])
            dfs(i,0);
    cout<<ans.size()<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}