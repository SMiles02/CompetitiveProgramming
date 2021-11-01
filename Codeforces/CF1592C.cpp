#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int a[N], x;
bool ansFound;
vector<int> e[N];

bool dfs(int c, int p)
{
    int ct=0;
    bool oneC=0;
    for (int i : e[c])
        if (i!=p)
        {
            if (dfs(i,c))
            {
                ++ct;
                oneC=1;
            }
            a[c]^=a[i];
        }
    if ((a[c]==0&&oneC)||ct>1)
        ansFound=1;
    return (oneC||a[c]==x);
}

void solve()
{
    int n,k,u,v;
    x=0;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        x^=a[i];
        e[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (x==0)
    {
        cout<<"YES\n";
        return;
    }
    if (k==2)
    {
        cout<<"NO\n";
        return;
    }
    ansFound=0;
    dfs(1,0);
    if (ansFound)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}