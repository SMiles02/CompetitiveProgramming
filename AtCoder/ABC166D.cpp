#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    for (ll a=-250;a<=250;++a)
        for (ll b=-250;b<=250;++b)
            if ((a*a*a*a*a)-(b*b*b*b*b)==n)
            {
                cout<<a<<" "<<b;
                return 0;
            }
    return 0;
}