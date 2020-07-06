#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,last,cur,ans1=0,ans2=0;
    cin>>n;
    cin>>last;
    for (int i=2;i<=n;++i)
    {
        cin>>cur;
        if (abs(cur-last)>1)
        {
            ans1=i-1;
            ans2=i;
        }
        last=cur;
    }
    if (ans1)
    {
        cout<<"YES\n"<<ans1<<" "<<ans2<<"\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}