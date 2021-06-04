#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5e5+4;
int ans[N][2], sub[N], h[N], t, tin[N], tout[N], pre[N];
bitset<N> sp;
vector<int> e[N], v;

void dfs(int c, int p)
{
    pre[++t]=c;
    tin[c]=t;
    sub[c]=1;
    h[c]=h[p]+1;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
    tout[c]=t;
}

int dfs(int c, int p, bool keep)
{
    //cout<<c<<"!\n";
    int mx = -1, big = -1, S=-1;
    for (int i : e[c])
        if (i!=p&&sub[i]>mx)
        {
            mx=sub[i];
            big=i;
        }
    for (int i : e[c])
        if (i!=p&&i!=big)
            S=max(S,dfs(i,c,0));
    if (big!=-1)
        S=max(S,dfs(big,c,1));
    if (sp[c])
        S=c;
    v.push_back(c);
    if (S!=-1)
    {
        for (int i : e[c])
            if (i!=p&&i!=big)
                if (ans[i][0]==-1)
                    for (int j=tin[i];j<=tout[i];++j)
                    {
                        ans[pre[j]][0]=2*h[c]-h[pre[j]];
                        ans[pre[j]][1]=S;
                    }
        for (int i : v)
        {
            ans[i][0]=2*h[c]-h[i];
            ans[i][1]=S;
        }
        v.clear();
    }
    else if (keep)
        for (int i : e[c])
            if (i!=p&&i!=big)
                if (ans[i][0]==-1)
                    for (int j=tin[i];j<=tout[i];++j)
                        v.push_back(pre[j]);
    if (keep==0)
        v.clear();
    return S;
}

void solve()
{
    int n,k,r,x,y;
    cin>>n>>k>>r;
    t=0;
    for (int i=1;i<=n;++i)
    {
        ans[i][0]=ans[i][1]=-1;
        sp[i]=0;
        e[i].clear();
    }
    while (k--)
    {
        cin>>x;
        sp[x]=1;
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(r,0);
    dfs(r,0,1);
    for (int j=0;j<2;++j)
    {
        for (int i=1;i<=n;++i)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    h[0]=-1;
    while (tc--)
        solve();
    return 0;
}