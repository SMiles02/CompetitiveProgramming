#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x;
    cin>>n;
    int a[n+2];
    set<int> s;
    a[0]=1e9;a[n+1]=a[0];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    if (s.size()==1)
    {
        cout<<"-1\n";
        return;
    }
    x=*(--s.end());
    for (int i=1;i<=n;++i)
        if (a[i]==x)
            if (a[i-1]<x||a[i+1]<x)
            {
                cout<<i<<"\n";
                return;
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