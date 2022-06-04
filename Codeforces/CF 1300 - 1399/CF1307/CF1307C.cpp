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
    int n;
    ll ans=0;
    string s;
    cin>>s;
    n=sz(s);
    map<char,ll> m;
    ++m[s[0]];
    map<pair<char,char>,ll> paired;
    for (int i=1;i<n;++i)
    {
        for (char c='a';c<='z';++c)
        {
            paired[{c,s[i]}]+=m[c];
        }
        ++m[s[i]];
    }
    for (char a='a';a<='z';++a)
    {
        ans=max(ans,m[a]);
        for (char b='a';b<='z';++b)
        {
            //cout<<a<<b<<" = "<<paired[{a,b}]<<"\n";
            ans=max(ans,paired[{a,b}]);
        }
    }
    cout<<ans;
    return 0;
}