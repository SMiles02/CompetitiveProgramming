#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t,n,x,y,l,r,m,beat1,beat2;
    cin>>t;
    while (t--)
    {
        cin>>n>>x>>y;
        beat1=n-x;
        beat2=n-y;
        l=1;r=n;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (beat1>=m)
            {
                if ()
            }
            else
            {

            }
        }
    }
    return 0;
}