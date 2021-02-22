#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,x,k;
    cin>>n>>x;
    ll s=0,t=0;
    while (n--)
    {
        cin>>k;
        s+=k;
        t+=(k+x-1)/x;
    }
    cout<<(s+x-1)/x<<" "<<t<<"\n";
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