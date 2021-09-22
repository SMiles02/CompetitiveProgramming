//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353;
int n,m,q,ans,x,y,t,d[2][2],c[2][2],r[2][2];
set<array<int,2>> s[2];

void remove_cell(int x, int y, int z)
{
    if (s[z].count({x,y})==0)
        continue;
    s[z].erase({x,y});
    --d[z][(x+y)&1];
    --r[z][x&1];
    --c[z][y&1];
}

void add_cell(int x, int y, int z)
{
    if (s[z].count({x,y}))
        continue;
    s[z].insert({x,y});
    ++d[z][(x+y)&1];
    ++r[z][x&1];
    ++c[z][y&1];
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    while (q--)
    {
        cin>>x>>y>>t;
        if (t==-1)
        {
            remove_cell(x,y,0);
            remove_cell(x,y,1);
        }
        else
        {
            remove_cell(x,y,1-t);
            add_cell(x,y,t);
        }
        ans=0;
        if (d[0][0]==0&&d[1][1]==0)
            ++ans;
        if (d[0][1]==0&&d[1][0]==0)
            ++ans;
        
    }
    return 0;
}