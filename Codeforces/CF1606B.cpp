#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,k,ans=0,c=1;
    cin>>n>>k;
    while (c<n&&c<k)
    {
        ++ans;
        c*=2;
    }
    cout<<ans+(max(0LL,n-c)+k-1)/k<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}