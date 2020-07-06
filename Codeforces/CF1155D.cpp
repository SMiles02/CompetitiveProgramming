#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b) return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a<b) return a;
    return b;
}

int n,x;

ll pos()
{
    ll maxi=-1000000000,cur=0,sum=0;
    int k;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        cur+=k;
        sum+=k;
        maxi=max(maxi,cur);
        cur=max(0,cur);
    }
    return 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    if (x>0)
        cout<<pos();
    else
        cout<<neg();
    return 0;
}