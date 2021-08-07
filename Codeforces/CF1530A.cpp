#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    sort(s.rbegin(), s.rend());
    cout<<s[0]<<"\n";
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