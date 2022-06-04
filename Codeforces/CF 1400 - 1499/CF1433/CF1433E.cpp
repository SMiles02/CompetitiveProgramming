#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll f[21];
    f[0]=1;
    for (int i=1;i<21;++i)
        f[i]=f[i-1]*i;
    int n;
    cin>>n;
    cout<<(f[n]/(f[n/2]*f[n/2]*2))*(f[n/2-1]*f[n/2-1]);
    return 0;
}