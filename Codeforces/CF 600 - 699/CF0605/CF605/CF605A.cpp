#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=0;
    cin>>n;
    map<int,int> m;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        m[k]=m[k-1]+1;
        ans=max(ans,m[k]);
        //cout<<k<<" "<<m[k]<<"\n";
    }
    cout<<n-ans;
    return 0;
}