#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=0,y,c=1,d=1;
    cin>>n;
    ll k,a[n];
    cin>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    y=n-1;
    sort(a,a+n);
    while (x<y)
    {
        if (c<d)
        {
            if (k<(a[x+1]-a[x])*c)
            {
                cout<<a[y]-a[x]-(k/c);
                return 0;
            }
            k-=(a[x+1]-a[x])*c;
            ++x;
            ++c;
        }
        else
        {
            if (k<(a[y]-a[y-1])*d)
            {
                cout<<a[y]-a[x]-(k/d);
                return 0;
            }
            k-=(a[y]-a[y-1])*d;
            --y;
            ++d;
        }
    }
    cout<<0;
    return 0;
}