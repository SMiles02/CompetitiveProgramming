#include <bits/stdc++.h>
using namespace std;

int r[50000][5];

bool cmp(int x, int y)
{
    int ct=0;
    for (int i=0;i<5;++i)
    {
        if (r[x][i]>r[y][i])
            --ct;
        else
            ++ct;
    }
    return ct>0;
}

void solve()
{
    int n,x=0;
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<5;++j)
            cin>>r[i][j];
    for (int i=1;i<n;++i)
        if (cmp(i,x))
            x=i;
    for (int i=0;i<n;++i)
        if (!cmp(x,i))
        {
            cout<<"-1\n";
            return;
        }
    cout<<x+1<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}