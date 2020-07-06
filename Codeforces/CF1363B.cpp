#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int o[1001];
int z[1001];

void solve()
{
    int n,ans=1000;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='0')
        {
            z[i+1]=z[i]+1;
            o[i+1]=o[i];
        }
        else
        {
            z[i+1]=z[i];
            o[i+1]=o[i]+1;
        }
    }
    for (int i=0;i<=n;++i)
        ans=min(ans,min(z[n]-z[i]+o[i]-o[0],o[n]-o[i]+z[i]-z[0]));
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}