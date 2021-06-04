#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cout<<n*3<<"\n";
    for (int i=1;i<=n;i+=2)
        cout<<"1 "<<i<<" "<<i+1<<"\n1 "<<i<<" "<<i+1<<"\n2 "<<i<<" "<<i+1<<"\n1 "<<i<<" "<<i+1<<"\n1 "<<i<<" "<<i+1<<"\n2 "<<i<<" "<<i+1<<"\n";
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