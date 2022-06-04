#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,ans=0,t,x,y;
    cin>>n>>q>>l;
    int a[n+2];
    a[0]=a[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i]>l&&a[i-1]<=l)
            ++ans;
    }
    while (q--)
    {
        cin>>t;
        if (t==0)
        {
            cout<<ans<<"\n";
            continue;
        }
        cin>>x>>y;
        if (a[x]>l)
            continue;
        a[x]+=y;
        if (a[x]<=l)
            continue;
        ++ans;
        if (a[x-1]>l)
            --ans;
        if (a[x+1]>l)
            --ans;
    }
    return 0;
}