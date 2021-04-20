#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    n+=3-k;
    if (n&1)
        cout<<n/2<<" "<<n/2<<" 1 ";
    else if (n%4==2)
        cout<<n/2-1<<" "<<n/2-1<<" 2 ";
    else
        cout<<n/2<<" "<<n/4<<" "<<n/4<<" ";
    for (int i=3;i<k;++i)
        cout<<"1 ";
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