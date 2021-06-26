#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll prefix[1200002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    for (int i=A;i<=B;++i)
    {
        ++prefix[i+B];
        --prefix[i+C+1];
    }
    for (int i=1;i<=1200000;++i)
        prefix[i]+=prefix[i-1];
    for (int i=1200000;i>=0;--i)
        prefix[i]+=prefix[i+1];
    ll ans=0;
    for (int i=C;i<=D;++i)
        ans+=prefix[i+1];
    cout<<ans;
    return 0;
}