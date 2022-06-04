#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    char c;
    m=min(m,n+4);
    int a[n+2],b[n+2];
    for (int i=1;i<=n;++i)
    {
        cin>>c;
        a[i]=c-'0';
    }
    a[0]=a[n+1]=0;
    while (m--)
    {
        for (int i=0;i<=n+1;++i)
            b[i]=a[i];
        for (int i=1;i<=n;++i)
            if (a[i]==0&&(a[i-1]^a[i+1])==1)
                b[i]=1;
        for (int i=1;i<=n;++i)
            a[i]=b[i];
    }
    for (int i=1;i<=n;++i)
        cout<<a[i];
    cout<<"\n";
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