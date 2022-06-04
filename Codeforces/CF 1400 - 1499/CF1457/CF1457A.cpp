#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    cout<<max(n-r,r-1)+max(m-c,c-1)<<"\n";
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