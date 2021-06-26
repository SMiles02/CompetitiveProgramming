#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll a,b,p,n;
    cin>>a>>b>>p;
    string s;
    cin>>s;
    n=sz(s);
    ll dp[n];
    if (s[n-2]==s[n-1])
    {
        if (s[n-1]=='A')
        {
            dp[n-1]=a;
        }
        else
        {
            dp[n-1]=b;
        }
    }
    else
    {
        dp[n-1]=0;
    }
    for (int i=n-2;i>=0;--i)
    {
        dp[i]=dp[i+1];
        if (s[i]!=s[i+1])
        {
            if (s[i]=='A')
            {
                dp[i]+=a;
            }
            else
            {
                dp[i]+=b;
            }
        }
    }
    dp[n-1]=0;
    for (int i=0;i<n;++i)
    {
        if (dp[i]<=p)
        {
            cout<<i+1<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}