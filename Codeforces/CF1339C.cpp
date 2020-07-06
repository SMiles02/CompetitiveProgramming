#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll powers[41];

void solve()
{
    int n,ans=0;
    cin>>n;
    ll a[n];
    ll curDiff;
    cin>>a[0];
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        if (a[i]<a[i-1])
        {
            curDiff=a[i-1]-a[i];
            for (int j=0;j<41;++j)
            {
                if (powers[j]>curDiff)
                {
                    ans=max(ans,j);
                    a[i]=a[i-1];
                    break;
                }
                else if (powers[j]==curDiff)
                {
                    ans=max(ans,j+1);
                    a[i]=a[i-1];
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll cur=1;
    for (int i=0;i<41;++i)
    {
        powers[i]=cur;
        cur*=2;
    }
    while (n--)
    {
        solve();
    }
    return 0;
}