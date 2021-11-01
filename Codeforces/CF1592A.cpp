#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,h,x;
    cin>>n>>h;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    x=(h/(a[n-2]+a[n-1]))*2;
    h%=(a[n-2]+a[n-1]);
    if (h==0)
        cout<<x;
    else if (h<=a[n-1])
        cout<<x+1;
    else
        cout<<x+2;
    cout<<"\n";
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