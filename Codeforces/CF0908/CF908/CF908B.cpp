#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,x,y,ans=0;
pair<int,int> d[] = {{0,-1},{0,1},{1,0},{-1,0}};
//left, right, down, up
string s[50],t;

bool isOk(int a, int b)
{
    if (0<=a&&a<n)
        if (0<=b&&b<m)
            if (s[a][b]!='#')
                return 1;
    return 0;
}

void check(vector<int> dir)
{
    int u=x,v=y;
    for (char c : t)
    {
        if (!isOk(u+d[dir[(c-'0')]].first,v+d[dir[(c-'0')]].second))
            return;
        u+=d[dir[(c-'0')]].first;
        v+=+d[dir[(c-'0')]].second;
        if (s[u][v]=='E')
        {
            ++ans;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='S')
            {
                x=i;
                y=j;
            }
    cin>>t;
    set<int> se;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            for (int k=0;k<4;++k)
                for (int l=0;l<4;++l)
                    if (i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
                        check({i,j,k,l});
    cout<<ans;
    return 0;
}