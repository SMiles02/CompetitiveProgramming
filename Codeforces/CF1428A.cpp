#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (b==d||a==c)
        cout<<abs(b-d)+abs(a-c)<<"\n";
    else
        cout<<abs(b-d)+abs(a-c)+2<<"\n";
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