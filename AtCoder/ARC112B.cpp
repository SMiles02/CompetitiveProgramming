#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
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
    ll b,c,ans,l1,r1;
    cin>>b>>c;
    if (b<0)
    {
        l1=b-(c/2);
        r1=min(-1,max(b,b+(c-2)/2));
        ans=r1-l1+1;
        l1=max(0,min(-b,-b-(c-1)/2));
        r1=max(-b,-b+(c-1)/2);
        cout<<ans+r1-l1+1;
    }
    else if (b==0)
    {
        l1=-(c/2);
        r1=max(0,(c-1)/2);
        cout<<r1-l1+1;
    }
    else
    {
        l1=min(-b,-b-(c-1)/2);
        if (b-(c-1)/2<1)
            r1=-1;
        else
            r1=-(b-(c-1)/2);
        //cout<<l1<<" "<<r1<<"\n";
        ans=r1-l1+1;
        l1=max(0,b-c/2);
        r1=max(b,b+(c-2)/2);
        //cout<<l1<<" "<<r1<<"\n";
        cout<<ans+r1-l1+1;
    }
    return 0;
}