#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+7;
bitset<N> d[2];
vector<int> e[2][N];
 
void dfs(int c, int x)
{
    d[x][c]=1;
    for (int i : e[x][c])
        if (!d[x][i])
            dfs(i,x);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        e[0][a].push_back(b);
        e[1][b].push_back(a);
    }
    dfs(1,0);
    dfs(1,1);
    for (int i=1;i<=n;++i)
    {
        if (!d[0][i])
        {
            cout<<"NO\n1 "<<i;
            return 0;
        }
        if (!d[1][i])
        {
            cout<<"NO\n"<<i<<" 1";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}