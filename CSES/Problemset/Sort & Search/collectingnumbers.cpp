#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n;
    int f[n+1];
    for (int i=0;i<n;++i)
    {
        cin>>x;
        f[x]=i;
    }
    x=1;
    for (int i=1;i<n;++i)
        if (f[i]>f[i+1])
            ++x;
    cout<<x;
    return 0;
}