#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,m,k,su=0,x,ans=0;
    cin>>n>>m;
    map<int,int> powers;
    for (int i=0;i<m;++i)
    {
        cin>>k;
        ++powers[k];
        su+=k;
    }
    if (su<n)
    {
        cout<<"-1\n";
        return;
    }
    x=n;
    vector<int> v;
    while (x)
    {
        v.push_back(x%2);
        x/=2;
    }
    k=1;
    for (int i=0;i<sz(v);++i)
    {
        if (v[i])
        {
            x=k;
            while (powers[x]==0)
            {
                x*=2;
            }
            while (x>k)
            {
                powers[x/2]+=2;
                --powers[x];
                ++ans;
                x/=2;
            }
            --powers[k];
        }
        powers[k*2]+=powers[k]/2;
        k*=2;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}