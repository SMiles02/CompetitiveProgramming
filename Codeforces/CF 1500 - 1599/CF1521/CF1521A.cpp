#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll a,b;
    cin>>a>>b;
    if (b==1)
        cout<<"NO\n";
    else
        cout<<"YES\n"<<a*b<<" "<<a<<" "<<a*b+a<<"\n";
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