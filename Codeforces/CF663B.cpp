#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int toInt(string s)
{
    int r = 0;
    for (auto i : s)
    {
        r*=10;
        r+=(i-'0');
    }
    return r;
}

void solve()
{
    //int n;
    string s;
    char c;
    for (int i=0;i<4;++i)
        cin>>c;
    cin>>s;
    ll cur=1988,b=10,m;
    for (int i=sz(s)-1;i>=0;--i)
    {
        m=toInt(s.substr(i,sz(s)-i));
        if (m<=(cur%b))
            cur+=b-(cur%b);
        cur+=m-(cur%b);
        b*=10;
    }
    cout<<cur<<"\n";
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