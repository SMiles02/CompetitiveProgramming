#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,x;
    cin>>a>>b>>x;
    string s="";
    char c='0',d='1';
    map<char,int> m;
    if (b>a)
    {
        swap(a,b);
        swap(c,d);
    }
    m[c]=a;
    m[d]=b;
    for (int i=0;i<=x;++i)
    {
        if (i%2)
        {
            s+=d;
            --m[d];
        }
        else
        {
            s+=c;
            --m[c];
        }
    }
    x=sz(s);
    for (int i=0;i<x;++i)
    {
        cout<<s[i];
        while (m[s[i]]>0)
        {
            cout<<s[i];
            --m[s[i]];
        }
    }
    return 0;
}