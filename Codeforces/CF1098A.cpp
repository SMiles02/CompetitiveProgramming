#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> children;
map<int,int> parent;
map<int,int> score;
vector<int> sumToPath = {0};

void dfs(int cur, int height, int curSum)
{
    int k=sz(children[cur]);
    if (height%2)
    {
        score[cur]=sumToPath[cur]-curSum;
    }
    else
    {
        if (k==0)
        {
            score[cur]=0;
            return;
        }
        int mini=sumToPath[children[cur][0]];
        for (int i=1;i<k;++i)
        {
            mini=min(mini,sumToPath[children[cur][i]]);
        }
        score[cur]=mini-curSum;
    }
    for (int i=0;i<k;++i)
    {
        dfs(children[cur][i],height+1,curSum+score[cur]);
    }
    return;
}

void rootDFS()
{
    score[1]=sumToPath[1];
    int k=sz(children[1]);
    for (int i=0;i<k;++i)
    {
        dfs(children[1][i],2,score[1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll ans=0;
    cin>>n;
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        parent[i]=k;
        children[k].push_back(i);
    }
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        sumToPath.push_back(k);
    }
    rootDFS();
    for (int i=1;i<=n;++i)
    {
        if (score[i]<0)
        {
            cout<<-1;
            return 0;
        }
        ans+=score[i];
    }
    cout<<ans;
    return 0;
}