#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,mn=100,mx=0,c=0;
    cin>>n;
    bool b;
    for (int i=0;i<n;++i)
    {
        cin>>b;
        if (b)
        {
            ++c;
            mx=max(mx,i);
            mn=min(mn,i);
        }
    }
    cout<<mx-mn-c+1<<"\n";
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