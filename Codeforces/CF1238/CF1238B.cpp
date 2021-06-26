#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve(int r,vector<int> v)
{
    int ans=0,blown=0;
    while (sz(v))
    {
        if (v.back()-blown<=0)
        {
            cout<<ans<<"\n";
            return;
        }
        v.pop_back();
        ++ans;
        blown+=r;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,n,r,k;
    vector<int> v;
    map<int,int> m;
    cin>>q;
    while (q--)
    {
        cin>>n>>r;
        for (int i=0;i<n;++i)
        {
            cin>>k;
            if (!m[k])
            {
                v.push_back(k);
                m[k]=1;
            }
        }
        sort(v.begin(), v.end());
        solve(r,v);
        v.clear();
        m.clear();
    }
    return 0;
}