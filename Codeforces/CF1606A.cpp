#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    s[0]=s.back();
    cout<<s<<"\n";
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