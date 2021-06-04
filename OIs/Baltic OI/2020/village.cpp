#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, ct, sub[N], eC[N], ans[2][N], cost;
long long tot;
bitset<N> done;
vector<int> e[N], v;

void dfs(int c, int p)
{
    int mx=0;
    sub[c]=1;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
            tot+=min(sub[i],n-sub[i])*2;
            mx=max(mx,sub[i]);
        }
    if (max(mx,n-sub[c])<=n/2)
        ct=c;
}

void dfsAns(int c, int p)
{
    v.push_back(c);
    for (int i : e[c])
        if (i!=p)
            dfsAns(i,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
        ans[0][i]=i;
    }
    ans[0][n]=n;
    stack<int> s;
    for (int i=1;i<=n;++i)
    {
        eC[i]=e[i].size();
        if (eC[i]==1)
            s.push(i);
    }
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        done[x]=1;
        for (int i : e[x])
            if (!done[i])
            {
                if (--eC[i]==1)
                    s.push(i);
                if (ans[0][x]!=x)
                    continue;
                cost+=2;
                swap(ans[0][x],ans[0][i]);
            }
    }
    for (int i=1;i<=n;++i)
        if (ans[0][i]==i)
        {
            cost+=2;
            swap(ans[0][i],ans[0][e[i][0]]);
        }
    dfs(1,0);
    dfsAns(ct,0);
    cout<<cost<<" "<<tot<<"\n";
    for (int i=0;i<n;++i)
        ans[1][v[i]]=v[(i+n/2)%n];
    for (int j=0;j<2;++j)
    {
        for (int i=1;i<=n;++i)
            cout<<ans[j][i]<<" ";
        cout<<"\n";
    }
    return 0;
}