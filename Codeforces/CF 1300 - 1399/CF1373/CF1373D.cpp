#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int a[200000];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    ll cur=0,maxi=0;
    for (int i=0;i+1<n;i+=2)
    {
        cur=max(0,cur);
        cur+=a[i+1]-a[i];
        maxi=max(maxi,cur);
    }
    cur=0;
    for (int i=1;i+1<n;i+=2)
    {
        cur=max(0,cur);
        cur+=a[i]-a[i+1];
        maxi=max(maxi,cur);
    }
    for (int i=0;i<n;i+=2)
        maxi+=a[i];
    cout<<maxi<<"\n";
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