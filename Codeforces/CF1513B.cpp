#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;
ll f[200001];

ll mul(ll a, ll b)
{
    return (a*b)%mod;
}

void solve()
{
    int n,x,y;
    cin>>n;
    map<int,int> m;
    cin>>x;
    m[x]=1;
    for (int i=1;i<n;++i)
    {
        cin>>y;
        ++m[y];
        x&=y;
    }
    if (m[x]<2)
        cout<<"0\n";
    else
        cout<<mul(mul(m[x],(m[x]-1)),f[n-2])<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<200001;++i)
        f[i]=(f[i-1]*i)%mod;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}