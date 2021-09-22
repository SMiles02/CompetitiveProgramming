#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (auto i : s)
    {
        if (i=='U')
            cout<<'D';
        else if (i=='D')
            cout<<'U';
        else
            cout<<i;
    }
    cout<<"\n";
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