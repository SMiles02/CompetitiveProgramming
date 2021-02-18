#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z,q;
    cin>>n>>q;
    int a[n+1],f[n+2];
    f[0]=0;f[n+1]=n+1;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        f[a[i]]=i;
    }
    z=1;
    for (int i=1;i<n;++i)
        if (f[i]>f[i+1])
            ++z;
    while (q--)
    {
        cin>>x>>y;
        if (f[a[x]]>f[a[x]+1])
            --z;
        if (f[a[x]-1]>f[a[x]])
            --z;
        if (f[a[y]]>f[a[y]+1])
            --z;
        if (f[a[y]-1]>f[a[y]])
            --z;
        if (min(a[x],a[y])+1==max(a[x],a[y])&&f[min(a[x],a[y])]>f[max(a[x],a[y])])
            ++z;
        swap(f[a[x]],f[a[y]]);
        swap(a[x],a[y]);
        if (f[a[x]]>f[a[x]+1])
            ++z;
        if (f[a[x]-1]>f[a[x]])
            ++z;
        if (f[a[y]]>f[a[y]+1])
            ++z;
        if (f[a[y]-1]>f[a[y]])
            ++z;
        if (min(a[x],a[y])+1==max(a[x],a[y])&&f[min(a[x],a[y])]>f[max(a[x],a[y])])
            --z;
        cout<<z<<"\n";
    }
    return 0;
}