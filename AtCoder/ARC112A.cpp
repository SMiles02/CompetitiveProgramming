#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll f(ll x)
{
    return (x*(x+1))/2;
}

void solve()
{
    int L,R;
    cin>>L>>R;
    if (R<2*L)
    {
        cout<<"0\n";
        return;
    }
    cout<<f(R-2*L+1)<<"\n";
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