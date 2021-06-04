#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+3;
int n, p[N], heavy[N], pos[N], head[N], height[N], ct;
vector<int> e[N];
 
int dfs(int c)
{
    int sz=1, mx=0, tmp;
    for (int i : e[c])
        if (i!=p[c])
        {
            p[i]=c;
            height[i]=height[c]+1;
            tmp=dfs(i);
            sz+=tmp;
            if (tmp>mx)
            {
                heavy[c]=i;
                mx=tmp;
            }
        }
    return sz;
}
 
void decompose(int c, int h)
{
    head[c]=h;
    pos[c]=++ct;
    if (heavy[c])
        decompose(heavy[c],h);
    for (int i : e[c])
        if (i!=p[c]&&i!=heavy[c])
            decompose(i,i);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,w,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>v[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    decompose(1,1);
    // for max on path queries, look at
    // path queries 2 in cses trees section
    return 0;
}