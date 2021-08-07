#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,ans=0;
    cin>>n;
    string s,t;
    cin>>s;
    t=s;
    sort(s.begin(), s.end());
    for (int i=0;i<n;++i)
        ans+=(s[i]!=t[i]);
    cout<<ans<<"\n";
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