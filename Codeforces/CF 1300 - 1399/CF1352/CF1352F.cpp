#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    string s="";
    if (a)
        for (int i=0;i<a+1;++i)
            s+="0";
    if (c)
        for (int i=0;i<c+1;++i)
            s+="1";
    if (a&&c)
        --b;
    while (b>0)
    {
        --b;
        if (sz(s)==0)
            s+="10";
        else if (s.back()=='1')
            s+='0';
        else
            s+='1';
    }
    cout<<s<<"\n";
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