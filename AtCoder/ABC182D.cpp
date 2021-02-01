#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    ll ans=0,cur=0,longest=0,pos=0;
    while (n--)
    {
        cin>>k;
        cur+=k;
        longest=max(longest,cur);
        ans=max(ans,pos+longest);
        pos+=cur;
    }
    cout<<ans;
    return 0;
}