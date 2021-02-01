#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll n,k;
vector<ll> v;

ll calc(int midPoint)
{
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        if (i<midPoint)
        {
            ans+=abs((v[midPoint]-(k*(midPoint-i)))-v[i]);
        }
        else
        {
            ans+=abs((v[midPoint]+(k*(i-midPoint)))-v[i]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x;
    cin>>n>>k;   
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if (n%2)
    {
        cout<<calc(n/2);
    }
    else
    {
        cout<<min(calc(n/2),calc(n/2-1));
    }
    return 0;
}