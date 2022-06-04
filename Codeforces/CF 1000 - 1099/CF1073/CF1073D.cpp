#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mini=1000000000,good=0;
    ll t,ans=0,total=0;
    cin>>n>>t;
    int prices[n];
    for (int i=0;i<n;++i)
    {
        cin>>prices[i];
        total+=prices[i];
        if (prices[i]<=t)
            ++good;
        mini=min(mini,prices[i]);
    }
    while (t>=mini)
    {
        ans+=(t/total)*good;
        t%=total;
        good=0;total=0;
        for (int i=0;i<n;++i)
        {
            if (prices[i]<=t)
            {
                t-=prices[i];
                ++ans;
            }
        }
        for (int i=0;i<n;++i)
        {
            if (prices[i]<=t)
            {
                ++good;
                total+=prices[i];
            }
        }
    }
    cout<<ans;
    return 0;
}