#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,y;
    cin>>n;
    set<int> ans;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
    {
        x=a[i];y=0;
        for (int j=i+1;j<n;++j)
        {
            if (a[j]>=x)
            {
                y=x;
                x=a[j];
            }
            else
                y=max(y,a[j]);
            ans.insert(x-y);
        }
    }
    cout<<sz(ans)<<"\n";
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