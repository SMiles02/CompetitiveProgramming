#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,cur1=0,cur2=0;
    ll ans=0;
    cin>>n;
    map<int,vector<int>> m;
    for (int i=0;i<2*n;++i)
    {
        cin>>k;
        m[k].push_back(i);
    }
    for (int i=1;i<=n;++i)
    {
        ans+=abs(max(m[i][0],m[i][1])-cur2)+abs(min(m[i][0],m[i][1])-cur1);
        cur1=min(m[i][0],m[i][1]);
        cur2=max(m[i][0],m[i][1]);
    }
    cout<<ans;
    return 0;
}