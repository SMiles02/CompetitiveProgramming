#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> children;
int maxH=0;

void dfs(int cur, int height)
{
    maxH=max(maxH,height);
    int k=sz(children[cur]);
    for (int i=0;i<k;++i)
    {
        dfs(children[cur][i],height+1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        children[k].push_back(i);
    }
    dfs(-1,-1);
    cout<<maxH;
    return 0;
}