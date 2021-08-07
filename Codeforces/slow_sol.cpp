#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int X = 6;
int n, m;
vector<int> v;
vector<bool> ans;

void solve(int k)
{
    bool ok=1;
    for (int i=1;i<n;++i)
        if (!(v[i]==v[i-1]+1||v[i]==1&&v[i-1]==n))
            ok=0;
    // cout<<k<<" ";
        // for (int i : v)
        //     cout<<i<<" ";
        // cout<<"\n";
    if (ok)
    {
        ans[(n+1-v[0])%n]=1;
        // cout<<k<<" ";
        // for (int i : v)
        //     cout<<i<<" ";
        // cout<<"\n";
    }
    if (k==m)
        return;
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            swap(v[i],v[j]);
            solve(k+1);
            swap(v[i],v[j]);
        }
}

void solve()
{
    cin>>n>>m;
    v.resize(n);
    ans.assign(n,0);
    for (int i=0;i<n;++i)
        cin>>v[i];
    solve(0);
    vector<int> pp;
    for (int i=0;i<n;++i)
        if (ans[i])
            pp.push_back(i);
    cout<<sz(pp)<<" ";
    for (int i : pp)
        cout<<i<<" ";
    cout<<"\n";
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