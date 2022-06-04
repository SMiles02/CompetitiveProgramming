#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,s;
    cin>>n;
    if (n%2==0)
    {
        s=sqrt(n/2);
        if (s*s==n/2)
        {
            cout<<"YES\n";
            return;
        }
    }
    if (n%4==0)
    {
        s=sqrt(n/4);
        if (s*s==n/4)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}