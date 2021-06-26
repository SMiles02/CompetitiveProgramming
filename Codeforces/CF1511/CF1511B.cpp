#include <bits/stdc++.h>
using namespace std;

int digLen(int x)
{
    int r=0;
    while (x)
    {
        ++r;
        x/=10;
    }
    return r;
}

void solve()
{
    int a,b,c,x=1,y=1;
    cin>>a>>b>>c;
    while (digLen(x)<a)
        x*=2;
    while (digLen(y)<c)
        y*=2;
    while (digLen(y)<b)
        y*=3;
    cout<<x<<" "<<y<<"\n";
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