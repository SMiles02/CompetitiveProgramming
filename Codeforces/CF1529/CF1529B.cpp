#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 2e9+7;

void solve()
{
    int n,mn=INF,k;
    cin>>n;
    vector<int> v;
    while (n--)
    {
        cin>>k;
        if (k<=0)
            v.push_back(k);
        else
            mn=min(mn,k);
    }
    sort(v.begin(), v.end());
    if (mn==INF)
    {
        cout<<sz(v)<<"\n";
        return;
    }
    if (sz(v)<2)
    {
        cout<<sz(v)+1<<"\n";
        return;
    }
    k=INF;
    for (int i=1;i<sz(v);++i)
        k=min(k,v[i]-v[i-1]);
    if (k>=mn)
        v.push_back(mn);
    cout<<sz(v)<<"\n";
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