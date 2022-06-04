#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll k,n,a,b,z=0;
    cin>>k>>n>>a>>b;
    if (k-b*n<=0)
    {
        cout<<"-1\n";
        return;
    }
    if ((k-b*n)%(a-b))
    {
        cout<<min((k-b*n)/(a-b),n)<<"\n";
    }
    else
    {
        cout<<min(max((k-b*n)/(a-b)-1,z),n)<<"\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        solve();
    }
    return 0;
}