#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,p,x,ans=INF;
    cin>>n;
    while (n--)
    {
        cin>>a>>p>>x;
        if (x-a>0)
            ans=min(ans,p);
    }
    if (ans==INF)
        ans=-1;
    cout<<ans;
    return 0;
}