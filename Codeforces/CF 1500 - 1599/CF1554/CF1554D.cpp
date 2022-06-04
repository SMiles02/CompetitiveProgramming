#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<"a\n";
        return;
    }
    for (int i=0;i<n/2;++i)
        cout<<"a";
    if (n&1)
        cout<<"bc";
    else
        cout<<"b";
    for (int i=0;i<n/2-1;++i)
        cout<<"a";
    cout<<"\n";
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