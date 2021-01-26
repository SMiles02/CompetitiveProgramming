#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 3e5+7, INF = 1e9;
int n,a[mn];

int sq(int a)
{
    return a*a;
}

int f(int x)
{
    int ans=0;
    for (int i=0;i<n;++i)
        ans+=sq(a[i]-x);
    //cout<<x<<": "<<ans<<"\n";
    return ans;
}

void solve()
{
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    int ans=INF;
    for (int i=-100;i<=100;++i)
        ans=min(ans,f(i));
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=1;
    while (n--)
        solve();
    return 0;
}