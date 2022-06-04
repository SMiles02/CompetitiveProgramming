#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,s;
    cin>>n>>s;
    cout<<s/(n-(n+1)/2+1)<<"\n";
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