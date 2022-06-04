#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[100],b[100],c[100];

void solve()
{
    int n,l;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    for (int i=0;i<n;++i)
        cin>>c[i];
    l=a[0];
    cout<<l<<" ";
    for (int i=1;i+1<n;++i)
    {
        if (a[i]!=l)
            l=a[i];
        else
            l=b[i];
        cout<<l<<" ";
    }
    if (l!=a[n-1]&&a[n-1]!=a[0])
        cout<<a[n-1];
    else if (l!=b[n-1]&&b[n-1]!=a[0])
        cout<<b[n-1];
    else
        cout<<c[n-1];
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