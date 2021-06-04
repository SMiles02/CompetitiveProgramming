#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l=1,r=1000,x;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        l=max(l,x);
    }
    for (int i=0;i<n;++i)
    {
        cin>>x;
        r=min(r,x);
    }
    cout<<max(0,r-l+1);
    return 0;
}