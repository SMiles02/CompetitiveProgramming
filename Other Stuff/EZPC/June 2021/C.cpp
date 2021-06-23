#include <bits/stdc++.h>
using namespace std;

int fd(string s, char c)
{
    for (int i=0;i<26;++i)
        if (s[i]==c)
            return i;
}

void solve()
{
    string s;
    cin>>s;
    bool ok = 1;
    int e=fd(s,'e'),z=fd(s,'z'),p=fd(s,'p'),c=fd(s,'c');
    if (c<z||c<p||p<z||c<e)
        ok=0;
    if (ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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