#include <bits/stdc++.h>
using namespace std;

int fd(string s, char c)
{
    for (int i=0;i<26;++i)
        if (s[i]==c)
            return i;
}

string solve()
{
    string s;
    cin>>s;
    int e=fd(s,'e'),z=fd(s,'z'),p=fd(s,'p'),c=fd(s,'c');
    if (c<z||c<p||p<z||c<e)
        return "NO\n";
    return "YES\n";
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