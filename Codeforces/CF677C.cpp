#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll mod=1000000007;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<char,int> m;
    string a="abcdefghijklmnopqrstuvwxyz", b="ABCDEFGHIJKLMNOPQRSTUVWXYZ",s;
    for (int i=0;i<10;++i)
    {
        m[i+'0']=i;
    }
    for (int i=0;i<26;++i)
    {
        m[a[i]]=i+36;
        m[b[i]]=i+10;
    }
    m['_']=63;
    m['-']=62;
    int n,k=0;
    ll x=1;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        k=m[s[i]];
        for (int j=0;j<6;++j)
        {
            if (!((k)&(1<<j)))
            {
                x*=3;
                x%=mod;
            }
        }
    }
    cout<<x;
    return 0;
}