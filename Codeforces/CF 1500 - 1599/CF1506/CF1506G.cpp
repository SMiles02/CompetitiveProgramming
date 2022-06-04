#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";
set<int> s[26];
set<char> c;

void solve()
{
    int n,x=-1,y;
    string t,ans="";
    cin>>t;
    n=sz(t);
    c.clear();
    for (int i=0;i<26;++i)
        s[i].clear();
    for (int i=0;i<n;++i)
    {
        c.insert(t[i]);
        s[t[i]-'a'].insert(i);
    }
    for (int i=0;i<sz(c);++i)
        for (int j=25;j>=0;--j)
            if (!s[j].empty())
            {
                if (s[j].lower_bound(x)==s[j].end())
                    continue;
                y=*(s[j].lower_bound(x));
                bool ok = 1;
                for (int k=25;k>=0;--k)
                {
                    if (s[k].empty()||j==k)
                        continue;
                    if (s[k].lower_bound(y)==s[k].end())
                        ok=0;
                }
                if (ok)
                {
                    ans+=alpha[j];
                    s[j].clear();
                    x=y;
                    break;
                }
            }
    cout<<ans<<"\n";
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