#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    string s;
    cin>>s;
    n=sz(s);
    string a="",b="";
    for (int i=0;i<n;++i)
    {
        if ((s[i]-'a')%2)
            a+=s[i];
        else
            b+=s[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (!sz(a)||!sz(b))
    {
        cout<<a<<b<<"\n";
        return;
    }
    if (abs((a[0]-'a')-(b.back()-'a'))!=1)
    {
        cout<<b<<a<<"\n";
        return;
    }
    if (abs((b[0]-'a')-(a.back()-'a'))!=1)
    {
        cout<<a<<b<<"\n";
        return;
    }
    cout<<"No answer\n";
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