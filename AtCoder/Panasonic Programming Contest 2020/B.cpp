#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b)
    {
        return b;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    if (n==1||m==1)
    {
        cout<<1;
        return 0;
    }
    cout<<(n*m)/2+min(n%2,m%2);
    return 0;
}