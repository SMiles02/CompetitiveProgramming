#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string small(string s)
{
    string t="";
    int n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='u')
        {
            t+="oo";
        }
        else if (i<n-1)
        {
            if (s[i]=='k'&&s[i+1]=='h')
            {
                t+='h';
                ++i;
            }
            else
            {
                t+=s[i];
            }
        }
        else
        {
            t+=s[i];
        }
    }
    return t;
}

string minimiser(string s)
{
    for (int i=0;i<400;++i)
    {
        s=small(s);
    }
    //cout<<s<<"\n";
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    set<string> s;
    cin>>n;
    string t;
    while (n--)
    {
        cin>>t;
        s.insert(minimiser(t));
    }
    cout<<sz(s);
    return 0;
}