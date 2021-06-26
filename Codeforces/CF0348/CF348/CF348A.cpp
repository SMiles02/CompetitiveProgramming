#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,maxi=1,sum=0;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
        sum+=a[i];
    }
    if (sum%(n-1))
    {
        cout<<max(maxi,sum/(n-1)+1);
    }
    else
    {
        cout<<max(maxi,sum/(n-1));
    }
    return 0;
}