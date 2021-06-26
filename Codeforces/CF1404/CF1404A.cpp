#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,o=0,z=0;
    string s;
    cin>>n>>k;
    cin>>s;
    for (int i=k;i<n;++i)
        if (s[i]=='?')
            s[i]=s[i-k];
    for (int i=n-k-1;i>=0;--i)
        if (s[i]=='?')
            s[i]=s[i+k];
    for (int i=k;i<n;++i)
        if (s[i]=='?')
            s[i]=s[i-k];
    for (int i=0;i<k;++i)
    {
        if (s[i]=='1')
            ++o;
        else if (s[i]=='0')
            ++z;
    }
    if (o>k/2||z>k/2)
    {
        cout<<"NO\n";
        return;
    }
    for (int i=k;i<n;++i)
        if (s[i]!=s[i-k])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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