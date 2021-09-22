#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    cout<<n/3+(n%3==1)<<" "<<n/3+(n%3==2)<<"\n";
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