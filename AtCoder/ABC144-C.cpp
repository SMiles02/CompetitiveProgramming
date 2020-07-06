#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,b,k;
    cin>>n;
    a=1;b=n;
    k=sqrt(n);
    for (int i=2;i<=k;++i)
    {
        if (n%i==0)
        {
            a=i;
            b=n/i;
        }
    }
    cout<<a+b-2;
    return 0;
}