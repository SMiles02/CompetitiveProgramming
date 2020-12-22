#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,bad=0;
    vector<pii> ans;
    cin>>n;
    int a[n+1],b[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    map<pii,vector<int>> m;
    for (int i=1;i<=n;++i)
    {
        //cout<<a[i]<<" "<<b[i]<<"!\n";
        if (a[i]!=b[i])
        {
            //cout<<"in\n";
            if (sz((m[{b[i],a[i]}])))
            {
                ans.push_back({i,m[{b[i],a[i]}].back()});
                --bad;
                m[{b[i],a[i]}].pop_back();
            }
            else
            {
                m[{a[i],b[i]}].push_back(i);
                ++bad;
            }
        }
    }
    if (bad)
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n"<<sz(ans)<<"\n";
    for (pii i : ans)
        cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}