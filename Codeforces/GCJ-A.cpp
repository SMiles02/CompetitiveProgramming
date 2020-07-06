#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int test=0,i;

void solve()
{
    int x,y,n;
    string s;
    cin>>x>>y;
    cin>>s;
    ++test;
    cout<<"Case #"<<test<<": ";
    n=sz(s);
    for (i=0;i<n;++i)
    {
        if (abs(x)+abs(y)<=i)
        {
            cout<<i<<"\n";
            return;
        }
        if (s[i]=='N')
            ++y;
        if (s[i]=='E')
            ++x;
        if (s[i]=='S')
            --y;
        if (s[i]=='W')
            --x;
    }
    if (abs(x)+abs(y)<=i)
        cout<<n;
    else cout<<"IMPOSSIBLE";
    cout<<"\n";
    return;
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