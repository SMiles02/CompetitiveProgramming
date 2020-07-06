#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
int a[200000];

bool works(int k)
{
    ll canDo=0;
    for (int i=0;i<n;++i)
    {
        canDo+=max(0,a[n-i-1]-(i/k));
    }
    if (canDo>=m) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    if (!works(n))
    {
        cout<<-1;
        return 0;
    }
    int l=1,r=n,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (works(m))
        {
            r=m;
        }
        else l=m+1;
    }
    cout<<l;
    return 0;
}