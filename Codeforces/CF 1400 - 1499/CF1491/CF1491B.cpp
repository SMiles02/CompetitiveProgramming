#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,u,v;
    cin>>n>>u>>v;
    int a[n];
    set<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i=1;i<n;++i)
        if (abs(a[i]-a[i-1])>1)
        {
            cout<<"0\n";
            return;
        }
    if (s.size()==1)
        cout<<v+min(u,v)<<"\n";
    else
        cout<<min(u,v)<<"\n";
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