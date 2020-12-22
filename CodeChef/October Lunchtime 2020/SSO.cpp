#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[60];

void solve()
{
    ll ans=0,cur=0,k;
    int n;
    cin>>n;
    for (int i=0;i<60;++i)
        a[i]=0;
    while (n--)
    {
        cin>>k;
        for (int i=0;i<30;++i)
            if ((1<<i)&k)
                ++a[i];
    }
    for (int i=0;i<60;++i)
    {
        cur+=a[i];
        if (cur)
            ans+=((ll)1<<i);
        cur/=2;
    }
    cout<<ans<<"\n";
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