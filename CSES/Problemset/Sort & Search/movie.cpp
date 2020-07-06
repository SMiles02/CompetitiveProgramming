#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,cur=0,ans=0;
    cin>>n;
    vector<pair<int,int>> vP;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        vP.push_back({b,a});
    }
    sort(vP.begin(), vP.end());
    for (int i=0;i<n;++i)
    {
        if (cur<=vP[i].second)
        {
            ++ans;
            cur=vP[i].first;
        }
    }
    cout<<ans;
    return 0;
}