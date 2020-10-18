#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(a,max(b,c))<<"\n";
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