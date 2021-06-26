#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,cur=1;
    int m,ans[19];
    cin>>n>>m;
    for (int i=1;i<19;++i)
    {
        cur*=10;
        ans[i]=(cur/m)%m;
    }
    if (n<19)
    {
        cout<<ans[n];
        return 0;
    }
    if (ans[18]==ans[17]&&ans[17]==ans[16]&&ans[16]==ans[15])
    {
        cout<<ans[18];
        return 0;
    }
    for (int i=1;i<19;++i)
        cout<<i<<": "<<ans[i]<<"\n";
    return 0;
}