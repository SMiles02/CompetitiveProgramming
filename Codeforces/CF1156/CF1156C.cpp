#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,z;
int a[200000];

bool check(int m)
{
    int k=n-m;
    for (int i=0;i+k<n;++i)
        if (a[i]+z>a[i+k])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>z;
    for (int i=0;i<n;++i)
        cin>>a[i];
    int l=0,r=n/2,m;
    sort(a,a+n);
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m))
            l=m;
        else
            r=m-1;
    }
    cout<<l;
    return 0;
}