#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for (ll i=n;1;++i)
    {
        if (i%10==k)
        {
            if (!(i%k))
            {
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}