#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    ll n,k,x,ans=0;
    cin>>n>>k;
    map<int,int> m;
    vector<int> v;
    while (n--)
    {
        cin>>x;
        x=(k-(x%k))%k;
        if (m[x])
            ++m[x];
        else
        {
            v.push_back(x);
            m[x]=1;
        }
    }
    for (int i : v)
        if (i>0)
            ans=max(ans,k*(m[i]-1)+i);
    if (ans>0)
        ++ans;
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