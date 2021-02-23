#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,a[100000];

int check(int r)
{
    int c=1,m=a[0]+r;
    for (int i=0;i<n;++i)
        if (abs(m-a[i])>r)
        {
            ++c;
            m=a[i]+r;
        }
    return c;
}

void solve()
{
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    int l=0,r=1e8,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m)<=k)
            r=m;
        else
            l=m+1;
    }
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}