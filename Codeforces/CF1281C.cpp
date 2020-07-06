#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int x,k,j,times;
ll ans,MOD=1000000007;
string s;

void solve()
{
    cin>>x;
    cin>>s;
    j=1;
    k=sz(s);
    while (k<x)
    {
        if (j==k)
        {
            cout<<k<<"\n";
            return;
        }
        times=s[j-1]-'0'-1;
        while (times)
        {
            for (int i=j;i<k;++i)
            {
                s.push_back(s[i]);
            }
            --times;
        }
        ++j;
        k=sz(s);
    }
    ans=k;
    while (j<=x)
    {
        ans=j+(max(ans-j,(ans-j+MOD)%MOD))*(s[j-1]-'0');
        ++j;
        ans%=MOD;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}