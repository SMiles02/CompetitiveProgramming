#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x=0;
    cin>>n>>k;
    for (int i=0;i<k;++i)
    {
        cout<<n-x<<" ";
        ++x;
    }
    for (int i=1;x<n;++i)
    {
        cout<<i<<" ";
        ++x;
    }
    return 0;
}