#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a[200000];

bool check(int k)
{
    int last=0,l=k,r=n-1;
    //cout<<k<<": \n";
    while (l<=r)
    {
        if (min(a[l],a[r])<last)
            return 0;
        //cout<<"added "<<min(a[l],a[r])<<"\n";
        last=min(a[l],a[r]);
        if (a[l]<a[r])
            ++l;
        else
            --r;
    }
    return 1;
}

void solve()
{
    int l=0,r,m;
    cin>>n;
    r=n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l<<"\n";
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