#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a[3];
    for (int i=0;i<3;++i)
        cin>>a[i];
    for (int i=0;i<3;++i)
    {
        int ans=0;
        for (int j=0;j<3;++j)
            if (i!=j)
                ans=max(ans,a[j]-a[i]+1);
        cout<<ans<<" ";
    }
    cout<<"\n";
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