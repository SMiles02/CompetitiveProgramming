#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1e9+7;

ll sq(ll a)
{
    return (a*a)%mod;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t,n,a,b;
    cin>>t;
    while (t--)
    {
        cin>>n>>a>>b;
        if (a+b>n)
            cout<<"0\n";
        else
        {   
            cout<<(sq(n-a+1)*sq(n-b+1))%mod<<"!\n";
            cout<<n-max(a,b)+1<<"\n";
            cout<<sq(n-max(a,b)+1)<<"\n";
            cout<<((sq(n-a+1)*sq(n-b+1))%mod+mod-sq(n-max(a,b)+1))%mod<<"\n";
        }
    }
    return 0;
}