#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,p,k,cur=0,ans=0,tot,curAns;
    cin>>n>>p>>k;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<k;++i)
    {
        tot=cur;
        if (tot<=p)
        {
            curAns=i;
            for (int j=i+k-1;j<n;j+=k)
            {
                tot+=a[j];
                if (tot>p)
                {
                    break;
                }
                curAns+=k;
            }
            ans=max(ans,curAns);
        }
        cur+=a[i];
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}