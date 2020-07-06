#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a,b,x,y,l,r,m;
ll k;
int p[200000];

ll check(int k)
{
    ll ans=0;
    int c=0,d=0,cd=0;
    for (int i=1;i<=k;++i)
    {
        if (!(i%a))
        {
            if (!(i%b))
                ++cd;
            else
                ++c;
        }
        else if (!(i%b))
            ++d;
    }
    if (x>y)
    {
        for (int i=n-1;i+1;--i)
        {
            if (cd)
            {
                --cd;
                ans+=((p[i]/100)*(x+y));
            }
            else if (c)
            {
                --c;
                ans+=((p[i]/100)*(x));
            }
            else if (d)
            {
                --d;
                ans+=((p[i]/100)*(y));
            }
            else
                return ans;
        }
    }
    else
    {
        for (int i=n-1;i+1;--i)
        {
            if (cd)
            {
                --cd;
                ans+=((p[i]/100)*(x+y));
            }
            else if (d)
            {
                --d;
                ans+=((p[i]/100)*(y));
            }
            else if (c)
            {
                --c;
                ans+=((p[i]/100)*(x));
            }
            else
                return ans;
        }
    }
    return ans;
}

void solve()
{
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>p[i];
    sort(p,p+n);
    cin>>x>>a;
    cin>>y>>b;
    cin>>k;
    if (check(n)<k)
    {
        cout<<"-1\n";
        return;
    }
    l=1;r=n;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m)<k) l=m+1;
        else r=m;
    }
    cout<<l<<"\n";
    return;
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