#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 4e5+1;
int p[mn],r[mn];

int find_set(int k)
{
    if (k==p[k])
        return k;
    return p[k]=find_set(p[k]);
}

void unite(int x, int y)
{
    x=find_set(x);
    y=find_set(y);
    if (x!=y)
    {
        if (r[x]<r[y])
            swap(x,y);
        p[y]=x;
        r[x]+=r[y];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z;
    cin>>n;
    for (int i=1;i<=2*n;++i)
    {
        p[i]=i;
        r[i]=1;
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>z;
        unite(n*z+x,n*z+y);
    }
    ll ans=0;
    for (int i=1;i<=n;++i)
        ans+=1LL*r[find_set(i)]*r[find_set(n+i)];
    cout<<ans-n;
    return 0;
}