#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a,ll b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n>>k;
    cout<<min(n%k,k-(n%k));
    return 0;
}