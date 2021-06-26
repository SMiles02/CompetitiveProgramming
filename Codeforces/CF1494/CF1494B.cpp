#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,u,r,d,l;
    cin>>n>>u>>r>>d>>l;
    for (int h=0;h<2;++h)
        for (int i=0;i<2;++i)
            for (int j=0;j<2;++j)
                for (int k=0;k<2;++k)
                    if (h+i<=u&&u<=h+i+n-2)
                        if (i+j<=r&&r<=i+j+n-2)
                            if (j+k<=d&&d<=j+k+n-2)
                                if (k+h<=l&&l<=k+h+n-2)
                                {
                                    cout<<"YES\n";
                                    return;
                                }
    cout<<"NO\n";
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