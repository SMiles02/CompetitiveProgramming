#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,k,l=1,r=1000000000,m;
    cin>>n>>k;
    while (l^r)
    {
        m=l+(r-l)/2;
        if (k*m<n)
            l=m+1;
        else
            r=m;
    }
    cout<<(k*l+n-1)/n<<"\n";
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