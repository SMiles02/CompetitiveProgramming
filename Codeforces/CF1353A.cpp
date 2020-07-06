#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll solve()
{
    ll n,m;
    cin>>n>>m;
    if (n==1)
        return 0;
    if (n==2)
        return m;
    return 2*m;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        cout<<solve()<<"\n";
    return 0;
}