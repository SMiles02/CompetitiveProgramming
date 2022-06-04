#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,x,t,k;
    cin>>n>>x>>t;
    k=min(t/x,n-1);
    cout<<k*(k-1)/2+(n-k)*k<<"\n";
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