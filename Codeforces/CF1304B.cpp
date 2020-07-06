#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string reverse(string s)
{
    int n=sz(s);
    string t="";
    for (int i=n-1;i+1;--i)
    {
        t+=s[i];
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    string ans="",s,t;
    map<string,int> m;
    vector<string> v;
    while (n--)
    {
        cin>>s;
        t=reverse(s);
        if (m[t])
        {
            ans+=s;
            --m[t];
        }
        else
        {
            ++m[s];
            if (s==t)
            {
                v.push_back(s);
            }
        }
    }
    t="";
    n=sz(v);
    for (int i=0;i<n;++i)
    {
        if (m[v[i]])
        {
            t=v[i];
        }
    }
    cout<<sz(ans)*2+sz(t)<<"\n"<<ans<<t<<reverse(ans);
    return 0;
}