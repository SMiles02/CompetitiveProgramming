#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n, b[300009];

int val(int i)
{
    if (i<2||i>=n)
        return 0;
    if ((b[i-1]<b[i]&&b[i]>b[i+1])||(b[i-1]>b[i]&&b[i]<b[i+1]))
        return 1;
    return 0;
}

void solve()
{
    int x=0,y=0,c,d;
    cin>>n;
    int a[n+2],weird[n+2];
    weird[0]=weird[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        weird[i]=0;
        cin>>a[i];
        b[i]=a[i];
    }
    if (n<3)
    {
        cout<<"0\n";
        return;
    }
    for (int i=2;i<n;++i)
        if ((a[i-1]<a[i]&&a[i]>a[i+1])||(a[i-1]>a[i]&&a[i]<a[i+1]))
        {
            ++x;
            weird[i]=1;
        }
    d=c=weird[1]+weird[2];
    for (int i=a[2]-1;i<a[2]+2;++i)
    {
        b[1]=i;
        d=min(d,val(1)+val(2));
    }
    y=max(y,c-d);
    b[1]=a[1];
    d=c=weird[n]+weird[n-1];
    for (int i=a[n-1]-1;i<a[n-1]+2;++i)
    {
        b[n]=i;
        d=min(d,val(n)+val(n-1));
    }
    y=max(y,c-d);
    b[n]=a[n];
    for (int i=2;i<n;++i)
    {
        d=c=weird[i-1]+weird[i]+weird[i+1];
        for (int j=a[i-1]-1;j<a[i-1]+2;++j)
        {
            b[i]=j;
            d=min(d,val(i-1)+val(i)+val(i+1));
        }
        for (int j=a[i+1]-1;j<a[i+1]+2;++j)
        {
            b[i]=j;
            d=min(d,val(i-1)+val(i)+val(i+1));
        }
        y=max(y,c-d);
        b[i]=a[i];
    }
    cout<<max(0,x-y)<<"\n";
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