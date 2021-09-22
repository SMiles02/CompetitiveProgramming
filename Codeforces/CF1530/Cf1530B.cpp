#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> v(n+3, vector<bool>(m+3));
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (i==1 || i==n || j==1 || j==m)
                v[i][j] = !(v[i][j-1] || v[i-1][j] || v[i-1][j-1] || v[i-1][j+1]);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            cout<<v[i][j];
        cout<<"\n";
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}