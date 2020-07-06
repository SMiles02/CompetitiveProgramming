#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string a,b,c;
    int n;
    cin>>a;
    cin>>b;
    cin>>c;
    n=sz(a);
    for (int i=0;i<n;++i)
    {
        if (!(a[i]==c[i]||b[i]==c[i]))
        {
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}