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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    double x,c;
    cin>>n>>m;
    if (m==0)
    {
        cout<<n<<" "<<n;
        return 0;
    }
    c=-m;
    x=0.5+sqrt(0.25+(-2*c));
    cout<<max(0,n-(2*m))<<" "<<n-ceil(x);
    return 0;
}