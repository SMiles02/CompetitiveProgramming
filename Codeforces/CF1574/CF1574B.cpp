#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    if (a+b+c-3<m||m<max({a,b,c})*2-a-b-c-1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}