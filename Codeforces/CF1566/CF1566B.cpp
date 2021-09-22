#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=sz(s),mx=0;
    for (auto i : s)
        mx += ((i-'0')==mx);
    if (mx<2)
    {
        cout<<mx<<"\n";
        return;
    }
    vector<int> v = {0};
    for (int i=1;i<n;++i)
        if (s[i]!=s[i-1])
            v.push_back(i);
    if (sz(v)>3)
        cout<<"2\n";
    else if (sz(v)==2||s[v[0]]=='1')
        cout<<"1\n";
    else
        cout<<"2\n";
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