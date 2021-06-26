#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int checker(string s, string t)
{
    int n=sz(s);
    string alpha="abcdefghijklmnopqrstuvwxyz";
    map<char,int> a;
    map<char,int> b;
    for (int i=0;i<n;++i)
    {
        ++a[s[i]];
        ++b[t[i]];
    }
    for (int i=0;i<26;++i)
    {
        if (a[alpha[i]]&&b[alpha[i]])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s,t;
    cin>>n;
    while (n--)
    {
        cin>>s;
        cin>>t;
        if (checker(s,t))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}