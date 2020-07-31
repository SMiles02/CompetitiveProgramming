#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
int a[200001];
int b[200001];
vector<int> children[200001];
ll s[200001];
vector<int> pos[200001];
vector<int> neg[200001];

void dfs(int c)
{
    s[c]=a[c];
    for (int i : children[c])
    {
        dfs(i);
        if (s[i]>0)
        {
            s[c]+=s[i];
            pos[c].push_back(i);
        }
        else
            neg[c].push_back(i);
    }
}

void dfsAns(int c)
{
    for (int i : pos[c])
        dfsAns(i);
    cout<<c<<" ";
    for (int i : neg[c])
        dfsAns(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll tot=0;
    cin>>n;
    vector<int> v;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        children[b[i]].push_back(i);
    }
    for (int i=1;i<=n;++i)
        if (b[i]==-1)
            dfs(i);
    for (int i=1;i<=n;++i)
        tot+=s[i];
    cout<<tot<<"\n";
    for (int i=1;i<=n;++i)
        if (b[i]==-1)
            dfsAns(i);
    return 0;
}