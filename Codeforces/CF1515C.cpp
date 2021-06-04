#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,x;
    cin>>n>>m>>x;
    int ans[n];
    vector<array<int,2>> a(n);
    for (int i=0;i<n;++i)
        cin>>a[i][0],a[i][1]=i;
    multiset<array<int,2>> s;
    array<int,2> t;
    sort(a.rbegin(), a.rend());
    for (auto i : a)
    {
        if (sz(s)<m)
        {
            s.insert({i[0],sz(s)+1});
            ans[i[1]]=sz(s);
        }
        else
        {
            t=*(s.begin());
            s.erase(s.begin());
            ans[i[1]]=t[1];
            t[0]+=i[0];
            s.insert(t);
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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