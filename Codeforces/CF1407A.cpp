#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
void solve()
{
    int n,o=0,z=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (a[i])
            ++o;
        else
            ++z;
    }
    if (z>=n/2)
    {
        cout<<z<<"\n";
        while (z--)
            cout<<"0 ";
        cout<<"\n";
        return;
    }
    if (o&1)
        --o;
    cout<<o<<"\n";
    while (o--)
        cout<<"1 ";
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