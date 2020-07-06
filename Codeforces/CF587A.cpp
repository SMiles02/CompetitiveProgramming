#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    int a[1000025]={0};
    cin>>n;
    while (n--)
    {
        cin>>x;
        ++a[x];
    }
    n=0;
    for (int i=0;i<1000024;++i)
    {
        a[i+1]+=(a[i]/2);
        n+=(a[i]%2);
    }
    cout<<n;
    return 0;
}