#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    cin>>n>>k;
    map<ll,ll> m;
    map<ll,ll> score;
    vector<ll> v;
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (x%k==0)
        {
            ans+=score[x/k];
            score[x]+=m[x/k];
        }
        ++m[x];
    }
    cout<<ans;
    return 0;
}