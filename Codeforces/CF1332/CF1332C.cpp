#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s;
    int n,k,ans=0,maxi;
    cin>>n>>k;
    cin>>s;
    map<char,int> m;
    for (int i=0;i<k/2;++i)
    {
        m.clear();
        for (int j=i;j<n;j+=k)
        {
            ++m[s[j]];
        }
        for (int j=k-1-i;j<n;j+=k)
        {
            ++m[s[j]];
        }
        maxi=0;
        for (char c='a';c<='z';++c)
        {
            maxi=max(maxi,m[c]);
        }
        //cout<<"maxi = "<<maxi<<"\n";
        ans+=(2*(n/k)-maxi);
    }
    if (k%2)
    {
        m.clear();
        for (int j=k/2;j<n;j+=k)
        {
            ++m[s[j]];
        }
        maxi=0;
        for (char c='a';c<='z';++c)
        {
            maxi=max(maxi,m[c]);
        }
        ans+=((n/k)-maxi);
    }
    cout<<ans<<"\n";
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