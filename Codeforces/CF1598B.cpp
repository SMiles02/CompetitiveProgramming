#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    int a[n][5];
    for (int i=0;i<n;++i)
        for (int j=0;j<5;++j)
            cin>>a[i][j];
    for (int i=0;i<5;++i)
        for (int j=0;j<5;++j)
            if (i!=j)
            {
                int x=0,y=0,z=0,t;
                for (int k=0;k<n;++k)
                {
                    if (a[k][i]==1&&a[k][j]==1)
                        ++z;
                    else if (a[k][i])
                        ++x;
                    else if (a[k][j])
                        ++y;
                }
                if (x<=n/2&&y<=n/2&&x+y+z==n)
                {
                    cout<<"YES\n";
                    return;
                }
            }
    cout<<"NO\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}