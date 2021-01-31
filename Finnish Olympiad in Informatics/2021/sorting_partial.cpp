#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

set<vector<int>> s;

void dfs(vector<int> v, int& n)
{
    if (s.find(v)!=s.end())
        return;
    s.insert(v);
    for (int i=0;i+1<n;++i)
        for (int j=i+2;j+1<n;++j)
        {
            swap(v[i],v[j]);
            swap(v[i+1],v[j+1]);
            dfs(v,n);
            swap(v[i],v[j]);
            swap(v[i+1],v[j+1]);
        }
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;++i)
        cin>>v[i];
    if (s.find(v)==s.end())
        cout<<"NO\n";
    else
        cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<9;++i)
    {
        vector<int> v(i);
        iota(v.begin(), v.end(), 1);
        dfs(v,i);
    }
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}