#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,a,b,c,d,q,ans;
string s[50];
bitset<50> done[50];
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool ok(int x, int y, int o1, int o2)
{
    if (a-1<=x&&x<c&&b-1<=y&&y<d&&!done[x][y]&&s[o1][o2]==s[x][y])
        return 1;
    return 0;
}

void dfs(int x, int y)
{
    done[x][y]=1;
    for (int i=0;i<4;++i)
        if (ok(x+dx[i],y+dy[i],x,y))
            dfs(x+dx[i],y+dy[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    for (int i=0;i<n;++i)
        cin>>s[i];
    while (q--)
    {
        cin>>a>>b>>c>>d;
        for (int i=a-1;i<c;++i)
            for (int j=b-1;j<d;++j)
                done[i][j]=0;
        ans=0;
        for (int i=a-1;i<c;++i)
            for (int j=b-1;j<d;++j)
                if (!done[i][j])
                {
                    ++ans;
                    dfs(i,j);
                }
        cout<<ans<<"\n";
    }
    return 0;
}