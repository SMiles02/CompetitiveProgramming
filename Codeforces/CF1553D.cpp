#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

string solve()
{
    string s,t;
    cin>>s;
    cin>>t;
    int j=sz(t)-1;
    for (int i=sz(s)-1;i>=0;--i)
    {
        if (s[i]==t[j])
            --j;
        else
            --i;
        if (j<0)
            return "YES\n";
    }
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