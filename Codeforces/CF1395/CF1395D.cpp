#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,d,m,k;
    cin>>n>>d>>m;
    vector<int> big;
    vector<int> smol;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k>m)
            big.push_back(k);
        else
            smol.push_back(k);
    }
    sort(big.rbegin(), big.rend());
    sort(smol.rbegin(), smol.rend());
    ll p1[sz(big)+1];
    ll p2[sz(smol)+1];
    p1[0]=0;
    p2[0]=0;
    for (int i=0;i<sz(big);++i)
        p1[i+1]=p1[i]+big[i];
    for (int i=0;i<sz(smol);++i)
        p2[i+1]=p2[i]+smol[i];
    ll ans=p2[sz(smol)];
    for (int i=1;i<=sz(big);++i)
    {
        if (i+(i-1)*d<=n)
        {
            ans=max(ans,p1[i]+p2[min(n-i-(i-1)*d,sz(smol))]);
            //cout<<i<<" "<<p1[i]<<" "<<p2[min(n-i-(i-1)*d,sz(smol))]<<"\n";
        }
        else
            break;
    }
    cout<<ans;
    return 0;
}