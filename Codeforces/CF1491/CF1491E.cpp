#include <bits/stdc++.h>
using namespace std;

const int mn = 2e5+7;
int sub[mn];
vector<int> f = {1,1}, edges[mn];
set<int> black[mn];

void dfs(int c, int p)
{
    sub[c]=1;
    for (int i : edges[c])
        if (i!=p&&black[c].find(i)==black[c].end())
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
}

bool check(int c, int k);

bool dfs(int c, int p, int k)
{
    for (int i : edges[c])
        if (i!=p&&black[c].find(i)==black[c].end())
        {
            if (sub[i]==f[k-1]||sub[i]==f[k-2])
            {
                black[i].insert(c);
                black[c].insert(i);
                bool b;
                if (sub[i]==f[k-1])
                    b = check(i,k-1) & check(c,k-2);
                else
                    b = check(i,k-2) & check(c,k-1);
                black[i].erase(black[i].find(c));
                black[c].erase(black[c].find(i));
                if (b)
                    return 1;
            }
            if (dfs(i,c,k))
                return 1;
        }
    return 0;
}

bool check(int c, int k)
{
    if (k==0||k==1)
        return 1;
    dfs(c,0);
    return dfs(c,0,k);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<30;++i)
        f.push_back(f[i-1]+f[i-2]);
    int n,x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i=0;i<30;++i)
        if (n==f[i])
            if (check(1,i))
            {
                cout<<"YES";
                return 0;
            }
    cout<<"NO";
    return 0;
}