#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    if (n<m)
    {
        swap(n,m);
    }
    if (k<n)
    {
        cout<<"-1\n";
        return;
    }
    if (n%2!=m%2)
    {
        --n;
        --k;
    }
    else if (n%2!=k%2)
    {
        --n;
        --m;
        k-=2;
    }
    cout<<max(k,0)<<"\n";
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