#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,ans=0;
    cin>>n;
    for (ll i=1;i*i<=2*n;++i)
    {
        if ((2*n)%i==0)
        {
            if (((2*n/i)-i+1)%2==0)
                ++ans;
            if (i*i!=2*n&&(i-(2*n/i)+1)%2==0)
                ++ans;
        }
    }
    cout<<ans;
    return 0;
}