#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
map<pair<int,int>,bool> done1;
map<pair<int,int>,bool> done2;
vector<string> s;

bool dfs1(int x, int y)
{
    if (done1[{x,y}])
        return 0;
    done1[{x,y}]=1;
    if (s[x][y]=='#')
        return 0;
    if (x==n-1&&y==m-1)
        return 1;
    bool check=0;
    if (x+1<n)
        check=dfs1(x+1,y);
    if (check)
        return 1;
    if (y+1<m)
        check=dfs1(x,y+1);
    return check;
}

bool dfs2(int x, int y)
{
    if (done2[{x,y}])
        return 0;
    done2[{x,y}]=1;
    if (s[x][y]=='#')
        return 0;
    if (x==n-1&&y==m-1)
        return 1;
    bool check=0;
    if (y+1<m)
        check=dfs2(x,y+1);
    if (check)
        return 1;
    if (x+1<n)
        check=dfs2(x+1,y);
    return check;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    s.resize(n);
    for (int i=0;i<n;++i)
        cin>>s[i];
    dfs1(0,0);
    dfs2(0,0);
    if (!(done1[{n-1,m-1}]||done2[{n-1,m-1}]))
    {
        cout<<0;
        return 0;
    }
    done1[{0,0}]=0;
    done2[{0,0}]=0;
    done1[{n-1,m-1}]=0;
    done2[{n-1,m-1}]=0;

    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (done1[{i,j}]&&done2[{i,j}])
            {
                cout<<1;
                return 0;
            }
    cout<<2;
    return 0;
}