#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n>>k;
    map<ll,int> m;
    for (int i=1;i<=k;++i)
    {
        if (m[n%i])
        {
            cout<<"No";
            return 0;
        }
        ++m[n%i];
    }
    cout<<"Yes";
    return 0;
}