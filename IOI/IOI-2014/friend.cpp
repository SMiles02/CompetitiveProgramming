#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> edges[1000];
bool done[1000];
int ans[2];

void dfs(int c, int x, int co[])
{
    ans[x]+=co[c];
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
            dfs(i,x^1,co);
}

int findSample(int n, int confidence[], int host[], int protocol[])
{
    for (int i=1;i<n;++i)
    {
        if (protocol[i]==0)
        {
            edges[i].push_back(host[i]);
            edges[host[i]].push_back(i);
        }
        else
        {
            for (int j : edges[host[i]])
            {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    int tot=0;
    for (int i=0;i<n;++i)
        if (!done[i])
        {
            ans[0]=0;
            ans[1]=0;
            dfs(i,0,confidence);
            tot+=max(ans[0],ans[1]);
        }
    return tot;
}

/**int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int c[n];
    for (int i=0;i<n;++i)
        cin>>c[i];
    int h[n];
    for (int i=1;i<n;++i)
        cin>>h[i];
    int p[n];
    for (int i=1;i<n;++i)
        cin>>p[i];
    cout<<findSample(n,c,h,p);
    return 0;
}**/