#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    ll ans;
    int n;
    cin>>t;
    while (t--)
    {
        ans=1;
        cin>>n;
        while (n)
        {
            if (n%2) ans*=2;
            n/=2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}