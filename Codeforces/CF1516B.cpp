#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n+1],p[n+1];
    p[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=p[i-1]^a[i];
    }
    if (p[n]==0)
    {
        cout<<"YES\n";
        return;
    }
    for (int i=1;i<=n;++i)
        if (p[i]==p[n])
            for (int j=i+1;j<n;++j)
                if (p[j]==0)
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