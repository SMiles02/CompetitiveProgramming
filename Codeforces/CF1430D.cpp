#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,x;
string s;
vector<int> v;

bool check(int k)
{
    int r=0;
    for (int i=0;i<k-1;++i)
        r=min(r+v[i]-1,i+1);
    for (int i=max(k-1,0);i<x;++i)
        r+=v[i];
    if (r>=k)
        return 1;
    return 0;
}

void solve()
{
    int l,r,m;
    cin>>n;
    cin>>s;
    v.clear();
    v.push_back(1);
    for (int i=1;i<n;++i)
    {
        if (s[i]==s[i-1])
            ++v.back();
        else
            v.push_back(1);
    }
    x=sz(v);
    l=1;r=x;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m))
            l=m;
        else
            r=m-1;
    }
    cout<<l<<"\n";
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