#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    int n,ans=0;
    cin>>n;
    double a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    t=ceil(a[0]/n);
    for (int i=1;i<n;++i)
    {
        if (ceil((a[i]-i)/n)<t)
        {
            t=ceil((a[i]-i)/n);
            ans=i;
        }
    }
    cout<<ans+1;
    return 0;
}