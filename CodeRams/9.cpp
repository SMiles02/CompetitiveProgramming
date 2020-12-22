#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int n;
string s[200];
bitset<200> done[200];
vector<pii> v;

bool ok(int x, int y)
{
    if (x<0||n<=x)
        return 0;
    if (y<0||n<=y)
        return 0;
    if (s[x][y]=='.')
        return 0;
    return 1;
}

void dfs(int x, int y)
{
    done[x][y]=1;
    v.push_back({x,y});
    if (ok(x-1,y))
        dfs(x-1,y);
    if (ok(x+1,y))
        dfs(x+1,y);
    if (ok(x,y-1))
        dfs(x,y-1);
    if (ok(x,y+1))
        dfs(x,y+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    bool b=1;
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n&&b;++i)
        for (int j=0;j<n&&b;++j)
            if (s[i][j]=='x')
            {
                dfs(i,j);
                b=0;
            }
    int gap=sz(v)/k;
    
    return 0;
}