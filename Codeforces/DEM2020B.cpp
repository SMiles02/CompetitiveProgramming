#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n][3];
    for (int i=0;i<n;++i)
        for (int j=0;j<3;++i)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            if (!((a[i][0]^a[j][0])&1))
                if (!((a[i][1]^a[j][1])&1))
                    if ((a[i][0]^a[j][0])||(a[i][1]^a[j][1]))
                        
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