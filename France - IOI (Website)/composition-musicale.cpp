#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string edit(string s)
{
    int n=sz(s);
    string t="";
    for (int i=0;i<n;++i)
    {
        if (sz(t))
        {
            if (s[i]==t.back())
            {
                t.pop_back();
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    for (int i=0;i<250;++i)
    {
        s=edit(s);
    }
    cout<<s;
    return 0;
}