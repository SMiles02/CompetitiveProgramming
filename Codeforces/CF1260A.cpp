#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll sq(ll x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll c,s;
    cin>>n;
    while (n--)
    {
        cin>>c>>s;
        cout<<(s%c)*sq((s/c+1))+(c-(s%c))*sq((s/c))<<"\n";
    }
    return 0;
}