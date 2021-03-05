#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int u,v;
    cin>>u>>v;
    if (u>v||__builtin_popcount(u)<__builtin_popcount(v))
    {
        cout<<"NO\n";
        return;
    }
    vector<int> x,y;
    for (int i=0;i<30;++i)
    {
        if ((1LL<<i)&u)
            x.push_back(i);
        if ((1LL<<i)&v)
            y.push_back(i);
    }
    for (int i=0;i<__builtin_popcount(v);++i)
        if (x[i]>y[i])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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