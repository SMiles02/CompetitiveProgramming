#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int cd[N], pt[N];
vector<int> e[N], a1, a2;
bitset<N> d, cut;

void dfs(int c, int p)
{
    cd[c]=0;
    pt[c]=p;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            if (!cut[i])
                ++cd[c];
        }
    if (cd[c]>1&&c!=1)
    {
        cut[c]=1;
        a1.push_back(c);
        a1.push_back(p);
    }
    for (int i : e[c])
        if (cd[c]>2&&i!=p&&!cut[i])
        {
            --cd[c];
            cut[i]=1;
            a1.push_back(i);
            a1.push_back(c);
        }
}

void dfs(int c)
{
    d[c]=1;
    int x=0;
    for (int i : e[c])
        if (((pt[i]==c&&!cut[i])||(pt[c]==i&&!cut[c])))
        {
            ++x;
            if (!d[i])
                dfs(i);
        }
    if (x<2)
        a2.push_back(c);
    if (x==0)
        a2.push_back(c);
}

void solve()
{
    int n,x,y,ans;
    cin>>n;
    a1.clear();
    a2.clear();
    for (int i=1;i<=n;++i)
    {
        d[i]=0;
        cut[i]=0;
        e[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
        if (!d[i])
            dfs(i);
    ans=a1.size();
    cout<<ans/2<<"\n";
    for (int i=0;i<ans;i+=2)
        cout<<a1[i]<<" "<<a1[i+1]<<" "<<a2[i+1]<<" "<<a2[i+2]<<"\n";
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