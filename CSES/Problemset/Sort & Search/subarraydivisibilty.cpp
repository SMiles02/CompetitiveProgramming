#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s=0,x;
    ll ans=0;
    cin>>n;
    map<int,int> m;
    m[0]=1;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        s+=x;
        s%=n;
        while (s<0)
            s+=n;
        ans+=m[s];
        ++m[s];
    }
    cout<<ans;
    return 0;
}