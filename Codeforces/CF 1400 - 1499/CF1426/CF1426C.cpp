#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int s=1,c=1,n,ans=0;
    cin>>n;
    while (s*s<n)
    {
        ++ans;
        ++s;
        ++c;
    }
    while (s<n)
    {
        ++ans;
        s+=c;
    }
    cout<<ans<<"\n";
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