#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dotsDoneRow[1001][1001];
int dotsDoneCol[1001][1001];
int u[1001][1001];
int d[1001][1001];
int l[1001][1001];
int r[1001][1001];
int done[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n>>m;
    string s[n];
    vector<pair<pair<int,int>,int>> v;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=1;j<m;++j)
            if (s[i][j-1]=='.')
                l[i][j]=0;
            else
                l[i][j]=l[i][j-1]+1;
    for (int i=0;i<n;++i)
        for (int j=m-2;j+1;--j)
            if (s[i][j+1]=='.')
                r[i][j]=0;
            else
                r[i][j]=r[i][j+1]+1;
    for (int i=1;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i-1][j]=='.')
                u[i][j]=0;
            else
                u[i][j]=u[i-1][j]+1;
    for (int i=n-2;i+1;--i)
        for (int j=0;j<m;++j)
            if (s[i+1][j]=='.')
                d[i][j]=0;
            else
                d[i][j]=d[i+1][j]+1;
    for (int i=1;i+1<n;++i)
        for (int j=1;j+1<m;++j)
        {
            if (s[i][j]=='*')
            {
                x=min(l[i][j],min(r[i][j],min(u[i][j],d[i][j])));
                if (x)
                {
                    v.push_back({{i+1,j+1},x});
                    ++dotsDoneRow[i][j-x];
                    --dotsDoneRow[i][j+x+1];
                    ++dotsDoneCol[i-x][j];
                    --dotsDoneCol[i+x+1][j];
                }
            }
        }
    for (int i=0;i<n;++i)
    {
        x=0;
        for (int j=0;j<m;++j)
        {
            x+=dotsDoneRow[i][j];
            if (x>0)
                done[i][j]=1;
        }
    }
    for (int j=0;j<m;++j)
    {
        x=0;
        for (int i=0;i<n;++i)
        {
            x+=dotsDoneCol[i][j];
            if (x>0)
                done[i][j]=1;
        }
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='*'&&!done[i][j])
            {
                cout<<-1;
                return 0;
            }
    x=sz(v);
    cout<<x<<"\n";
    for (int i=0;i<x;++i)
        cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<"\n";
    return 0;
}