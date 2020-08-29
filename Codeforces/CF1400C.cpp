#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s,t,u;
    cin>>s;
    int n=sz(s),x;
    cin>>x;
    for (int i=0;i<n;++i)
        t+='1';
    for (int i=0;i<n;++i)
        if (s[i]=='0')
        {
            if ((i-x)>=0)
                t[i-x]='0';
            if (i+x<n)
                t[i+x]='0';
        }
    for (int i=0;i<n;++i)
    {
        if (i-x>=0&&t[i-x]=='1')
        {
            if (s[i]!='1')
            {
                cout<<"-1\n";
                return;
            }
        }
        else if (i+x<n&&t[i+x]=='1')
        {
            if (s[i]!='1')
            {
                cout<<"-1\n";
                return;
            }
        }
        else if (s[i]!='0')
        {
            cout<<"-1\n";
            return;
        }
    }
    cout<<t<<"\n";
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