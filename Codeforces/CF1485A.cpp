#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,d,e,ans=100;
    cin>>a>>b;
    for (int i=0;i<40;++i)
    {
        c=a;d=b+i;e=i;
        if (d==1)
            continue;
        while (c)
        {
            c/=d;
            ++e;
        }
        ans=min(ans,e);
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