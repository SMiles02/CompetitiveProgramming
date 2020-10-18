#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int l,r,m;
ll INF = 1e18;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int binsearchUp(int a[], int n, int k)
{
    if (n==0||a[n-1]<k)
        return -1;
    l=0;r=n-1;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (a[m]<k)
            l=m+1;
        else
            r=m;
    }
    return a[l];
}

int binsearchDown(int a[], int n, int k)
{
    if (n==0||a[0]>k)
        return -1;
    l=0;r=n-1;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (a[m]>k)
            r=m-1;
        else
            l=m;
    }
    return a[l];
}



signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,cL,cV,v,q,x1,y1,x2,y2,k;
    ll ans;
    cin>>n>>m>>cL>>cV>>v;
    int l[cL],e[cV];
    for (int i=0;i<cL;++i)
        cin>>l[i];
    for (int i=0;i<cV;++i)
        cin>>e[i];
    sort(l,l+cL);
    sort(e,e+cV);
    cin>>q;
    while (q--)
    {
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2)
        {
            cout<<abs(y1-y2)<<"\n";
            continue;
        }
        ans=INF;
        k=binsearchDown(l,cL,y1);
        if (k>-1)
            ans=min(ans,abs(k-y1)+abs(k-y2)+abs(x1-x2));
        k=binsearchUp(l,cL,y1);
        if (k>-1)
            ans=min(ans,abs(k-y1)+abs(k-y2)+abs(x1-x2));
        k=binsearchDown(e,cV,y1);
        if (k>-1)
            ans=min(ans,abs(k-y1)+abs(k-y2)+(abs(x1-x2)+v-1)/v);
        k=binsearchUp(e,cV,y1);
        if (k>-1)
            ans=min(ans,abs(k-y1)+abs(k-y2)+(abs(x1-x2)+v-1)/v);
        cout<<ans<<"\n";
    }
    return 0;
}