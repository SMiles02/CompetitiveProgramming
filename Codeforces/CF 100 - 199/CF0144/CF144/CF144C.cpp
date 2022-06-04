#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int q=0,k=0;
int cur[26];
int ans[26];

void check()
{
    int c=0;
    for (int i=0;i<26;++i)
    {
        if (ans[i]<cur[i])
            return;
        c+=(ans[i]-cur[i]);
    }
    if (q==c)
        ++k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    string s,t;
    cin>>s;
    cin>>t;
    n=sz(s);
    m=sz(t);
    if (m>n)
    {
        cout<<0;
        return 0;
    }
    for (int i=0;i<m;++i)
    {
        if (s[i]=='?')
            ++q;
        else
            ++cur[s[i]-'a'];
    }
    for (auto c : t)
        ++ans[c-'a'];
    check();
    for (int i=m;i<n;++i)
    {
        if (s[i]=='?')
            ++q;
        else
            ++cur[s[i]-'a'];
        if (s[i-m]=='?')
            --q;
        else
            --cur[s[i-m]-'a'];
        check();
    }
    cout<<k;
    return 0;
}