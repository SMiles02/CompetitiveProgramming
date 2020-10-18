#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,lastDone=2,k,ans=0;
    cin>>n;
    ll s=0;
    map<ll,int> m;
    m[0]=1;
    for (int i=2;i<=n+1;++i)
    {
        cin>>k;
        s+=k;
        if (m[s]>=lastDone-1)
        {
            ++ans;
            lastDone=i;
        }
        m[s]=i;
    }
    cout<<ans<<"\n";
    return 0;
}