#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    if (n&1)
        cout<<n/2<<" "<<n/2<<" 1\n";
    else if (n%4==2)
        cout<<n/2-1<<" "<<n/2-1<<" 2\n";
    else
        cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
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