#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    string s;
    string t;
    string interim;
    map<char,int> m1;
    map<char,int> m2;
    cin>>n;
    cin>>s;
    cin>>t;
    for (int i=0;i<n;++i)
    {
        ++m1[s[i]];
        ++m2[t[i]];
    }
    for (char c='a';c<='z';++c)
        if (m1[c]!=m2[c])
        {
            cout<<"-1\n";
            return;
        }
    int ans=0,l=0,r=n-1,m;
    while (1)
    {
        while (s[r]==t[r]&&l<=r)
            --r;
        while (s[l]==t[l]&&l<=r)
            ++l;
        if (l>r)
        {
            cout<<ans<<"\n";
            return;
        }
        m=r;
        while (s[m]!=t[l])
            --m;
        interim="";
        for (int i=0;i<l;++i)
            interim+=s[i];
        interim+=s[m];
        for (int i=l;i<m;++i)
            interim+=s[i];
        for (int i=m+1;i<n;++i)
            interim+=s[i];
        s=interim;
    }
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