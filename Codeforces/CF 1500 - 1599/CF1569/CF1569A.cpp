#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=1;i<n;++i)
        if (s[i]!=s[i-1])
        {
            cout<<i<<" "<<i+1<<"\n";
            return;
        }
    cout<<"-1 -1\n";
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