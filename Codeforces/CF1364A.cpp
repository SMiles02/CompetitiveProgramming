#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,x;
int p[100001];

bool check(int k)
{
    for (int i=k;i<=n;++i)
        if ((p[i]-p[i-k])%x)
            return 1;
    return 0;
}

void solve()
{
    bool b=0;
    cin>>n>>x;
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        if (p[i]%x)
            b=1;
        p[i]+=p[i-1];
    }
    int l=1,r=n,m;
    if (!b)
    {
        cout<<"-1\n";
        return;
    }
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m))
            l=m;
        else
            r=m-1;
    }
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    p[0]=0;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}