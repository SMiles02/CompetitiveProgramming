#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    for (auto i : t)
        if (i=='o')
            return "YES\n";
    return "NO\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        cout<<solve();
    return 0;
}