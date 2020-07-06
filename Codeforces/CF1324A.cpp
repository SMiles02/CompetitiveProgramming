#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,odds=0,evens=0;
    cin>>n;
    while (n--)
    {
        cin>>k;
        if (k%2)
        {
            ++odds;
        }
        else
        {
            ++evens;
        }
    }
    if (min(odds,evens)==0)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}