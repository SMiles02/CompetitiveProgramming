#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[100000],n;

bool check(int x)
{
    vector<int> v(x),w(x+1);
    for (int i=0;i<x;++i)
        v[i]=a[i];
    for (int i=n-x-1;i<n;++i)
        w[i-n+x+1]=a[i];
    for (int i=0;i<x;++i)
        if (w[i]<=v[i])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,r,m,x;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    l=0;r=(n-1)/2;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m))
            l=m;
        else
            r=m-1;
    }
    x=l;
    vector<int> v(x),w(x+1);
    cout<<l<<"\n";
    for (int i=0;i<x;++i)
        v[i]=a[i];
    for (int i=n-x-1;i<n;++i)
        w[i-n+x+1]=a[i];
    for (int i=0;i<x;++i)
        cout<<w[i]<<" "<<v[i]<<" ";
    cout<<a[n-1]<<" ";
    for (int i=x;i<n-x-1;++i)
        cout<<a[i]<<" ";
    return 0;
}