#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int x=0;

void solve()
{
    cout<<"Case #"<<x<<": ";
    int n,open=0;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='1')
        {
            if (!open)
            {
                open=1;
                cout<<"(";
            }
        }
        if (s[i]=='0')
        {
            if (open)
            {
                open=0;
                cout<<")";
            }
        }
        cout<<s[i];
    }
    if (open)
    {
        cout<<")";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        ++x;
        solve();
        cout<<"\n";
    }
    return 0;
}