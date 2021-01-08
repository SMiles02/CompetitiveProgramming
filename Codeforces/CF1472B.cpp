#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,o=0,t=0;
    cin>>n;
    while (n--)
    {
        cin>>k;
        if (k==1)
            ++o;
        else
            ++t;
    }
    t&=1;
    if (o&1)
        cout<<"NO\n";
    else if (t&&o==0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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