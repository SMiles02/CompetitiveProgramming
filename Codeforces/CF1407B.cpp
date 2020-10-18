#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m=0,l=0,k;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (a[i]>m)
        {
            m=a[i];
            l=i;
        }
    }
    cout<<m<<" ";
    a[l]=0;
    k=m;
    for (int j=1;j<n;++j)
    {
        m=0;l=0;
        for (int i=0;i<n;++i)
            if (a[i]!=0)
            {
                if (gcd(a[i],k)>m)
                {
                    m=gcd(a[i],k);
                    l=i;
                }
            }
        cout<<a[l]<<" ";
        a[l]=0;
        k=m;
    }
    cout<<"\n";
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