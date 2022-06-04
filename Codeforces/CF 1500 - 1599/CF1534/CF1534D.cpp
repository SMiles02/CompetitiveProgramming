#include <bits/stdc++.h>
using namespace std;

bool local = 0;
int n, x, y, a[2021], b[2];
vector<int> e[2021];
vector<array<int,2>> ans;

void dfs(int c, int p, int h)
{
    a[c]=h;
    for (int i : e[c])
        if (i!=p)
            dfs(i,c,h+1);
}

void query(int k)
{
    cout<<"? "<<k<<endl;
    if (local)
        dfs(k,0,0);
    else
        for (int i=1;i<=n;++i)
            cin>>a[i];
}

void printAns()
{
    cout<<"!"<<endl;
    for (auto i : ans)
        cout<<i[0]<<" "<<i[1]<<endl;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    if (local)
        for (int i=1;i<n;++i)
        {
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
    query(1);
    vector<int> toCheck;
    for (int i=1;i<=n;++i)
        ++b[a[i]&1];
    if (b[0]>b[1])
    {
        for (int i=2;i<=n;++i)
            if (a[i]&1)
                toCheck.push_back(i);
    }
    else
        for (int i=2;i<=n;++i)
        {
            if (!(a[i]&1))
                toCheck.push_back(i);
            else if (a[i]==1)
                ans.push_back({1,i});
        }
    for (int i : toCheck)
    {
        query(i);
        for (int j=1;j<=n;++j)
            if (a[j]==1)
                ans.push_back({i,j});
    }
    printAns();
    return 0;
}