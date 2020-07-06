#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
int p[200000];

ll check(int x)
{
    ll ans=0;
    for (int i=0;i<n;++i)
        ans+=abs(x-p[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>p[i];
    if (check(1)<check(2))
    {
        cout<<check(1);
        return 0;
    }
    int l=2,r=1000000000,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m-1)>=check(m))
            l=m;
        else
            r=m-1;
    }
    cout<<check(l);
    return 0;
}