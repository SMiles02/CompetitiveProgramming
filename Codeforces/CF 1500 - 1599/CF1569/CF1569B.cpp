#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string> ans(n,string(n,'='));
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='2')
            v.push_back(i);
        ans[i][i]='X';
    }
    if (sz(v)==1||sz(v)==2)
    {
        cout<<"NO\n";
        return;
    }
    if (!v.empty())
        v.push_back(v[0]);
    cout<<"YES\n";
    for (int i=1;i<sz(v);++i)
    {
        ans[v[i]][v[i-1]]='+';
        ans[v[i-1]][v[i]]='-';
    }
    for (auto i : ans)
        cout<<i<<"\n";
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