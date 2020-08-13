#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,v,a[200001];
vector<int> e[200001];

void dfs(int c, int p)
{
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            a[c]+=a[i]+1;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;++i)
    {
        cin>>v;
        e[v].push_back(i);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}