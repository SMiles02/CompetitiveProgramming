#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,x,y;
    cin>>n>>q;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    while (q--)
    {
        cin>>t;
        if (t==0)
        {
            cin>>x>>y;
            a[x]=y;
            continue;
        }
        cin>>x;
        int ans = 1;
        while (x+a[x]<=n)
        {
            x+=a[x];
            ++ans;
        }
        cout<<x<<" "<<ans<<endl;
    }
    return 0;
}