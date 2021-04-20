#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const int N = 1e5;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p=0;
    ll m=0;
    cin>>n;
    string a,b;
    vector<int> v(n),w(n);
    vector<array<int,3>> ans,print;
    cin>>a;
    cin>>b;
    for (int i=0;i<n;++i)
        v[i]=a[i]-'0';
    for (int i=0;i<n;++i)
        w[i]=b[i]-'0';
    for (int i=0;i+1<n;++i)
    {
        if (v[i]>w[i])
        {
            m+=v[i]-w[i];
            ans.push_back({i,-1,v[i]-w[i]});
            v[i+1]-=(v[i]-w[i]);
            v[i]=w[i];
        }
        while (v[i]<w[i])
        {
            m+=w[i]-v[i];
            ans.push_back({i,1,w[i]-v[i]});
            v[i+1]+=(w[i]-v[i]);
            v[i]=w[i];
        }
    }
    if (v[n-1]!=w[n-1])
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<m<<"\n";
    while (!ans.empty())
    {
        while (ans.back()[2]>0&&p<N)
        {
            cout<<ans.back()[0]+1<<" "<<ans.back()[1]<<"\n";
            ++p;
            --ans.back()[2];
        }
        ans.pop_back();
    }
    return 0;
}