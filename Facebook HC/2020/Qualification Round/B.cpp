#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,a=0,b=0;
    string s;
    cin>>n;
    cin>>s;
    for (auto c : s)
    {
        if (c=='A')
            ++a;
        else
            ++b;
    }
    if (abs(a-b)==1)
        cout<<"Y\n";
    else
        cout<<"N\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}