#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    if (n==1)
    {
        cout<<1;
        return 0;
    }
    if (n==2)
    {
        cout<<2;
        return 0;
    }
    if (n%2)
    {
        cout<<n*(n-1)*(n-2);
        return 0;
    }
    if (n%3)
    {
        cout<<n*(n-1)*(n-3);
        return 0;
    }
    cout<<max((n/2)*(n-1)*(n-2),(n-3)*(n-1)*(n-2));
    return 0;
}