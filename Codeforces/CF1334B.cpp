#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

void solve()
{
    int n,x,k,ans=0;
    ll excess=0;
    vector<int> v;
    cin>>n>>x;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k>=x)
        {
            ++ans;
            excess+=(k-x);
        }
        else
        {
            v.push_back(k);
        }
    }
    sort(v.begin(), v.end());
    while (sz(v)&&(x-v.back())<=excess)
    {
        excess-=(x-v.back());
        v.pop_back();
        ++ans;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}