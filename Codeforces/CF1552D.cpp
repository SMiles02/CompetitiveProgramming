#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x,y;
    cin>>n;
    bool ok=0;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ok|=(a[i]==0);
    }
    for (int i=0;i<(1<<n);++i)
    {
        x=0;
        for (int j=0;j<n;++j)
            if (i&(1<<j))
                x+=a[j];
        for (int j=1;j<(1<<n);++j)
            if ((i&j)==0)
            {
                y=0;
                for (int k=0;k<n;++k)
                    if (j&(1<<k))
                        y+=a[k];
                ok|=(abs(x)==abs(y));
            }
    }
    if (ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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