#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[50];

void solve()
{
    int n,o=0,e=0,p=0;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    if (a[0]%2)
        ++o;
    else
        ++e;
    for (int i=1;i<n;++i)
    {
        if (a[i]-a[i-1]==1)
            ++p;
        if (a[i]%2)
            ++o;
        else
            ++e;
    }
    if (o%2==0&&e%2==0)
    {
        cout<<"YES\n";
        return;
    }
    if (o%2&&e%2&&p)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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