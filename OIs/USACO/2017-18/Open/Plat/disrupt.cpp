#include <bits/stdc++.h>
#define spi set<array<int,2>>
using namespace std;

const int N = 5e4+5;
int pt[N], ans[N];
vector<int> e[N];
vector<array<int,2>> r[N];

spi dfs(int c, int p)
{
    spi cur;
    pt[c]=p;
    for (int i : e[c])
        if (i!=p)
        {
            spi tp = dfs(i,c);
            if (tp.size()>cur.size())
                swap(tp,cur);
            for (auto i : tp)
            {
                if (cur.count(i))
                    cur.erase(i);
                else
                    cur.insert(i);
            }
        }
    for (auto i : r[c])
    {
        if (cur.count(i))
            cur.erase(cur.find(i));
        else
            cur.insert(i);
    }
    if (!cur.empty())
        ans[c]=(*cur.begin())[0];
    else
        ans[c]=-1;
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("disrupt.in", "r", stdin);
    //freopen("disrupt.out", "w", stdout);
    int n,m,x,y,z;
    cin>>n>>m;
    array<int,2> a[n];
    for (int i=1;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        e[a[i][0]].push_back(a[i][1]);
        e[a[i][1]].push_back(a[i][0]);
    }
    while (m--)
    {
        cin>>x>>y>>z;
        r[x].push_back({z,m});
        r[y].push_back({z,m});
    }
    dfs(1,0);
    for (int i=1;i<n;++i)
    {
        if (pt[a[i][0]]==a[i][1])
            cout<<ans[a[i][0]]<<"\n";
        else
            cout<<ans[a[i][1]]<<"\n";
    }
    return 0;
}