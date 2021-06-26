#include <bits/stdc++.h>
using namespace std;

int a[50];

void solve()
{
    int n;
    cin>>n;
    for (int i=0;i<n*2;++i)
        cin>>a[i];
    sort(a,a+n*2);
    for (int i=0;i<n;++i)
        cout<<a[i]<<" "<<a[i+n]<<" ";
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