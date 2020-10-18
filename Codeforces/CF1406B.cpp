#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = -1e18;
vector<int> v;

ll calc()
{
    ll ans=1;
    for (int i : v)
    {
        //cout<<i<<" ";
        ans*=i;
    }
    //cout<<"\n";
    return ans;
}

void solve()
{
    int n,k,z=0;
    ll ans=INF;
    cin>>n;
    vector<int> pos,neg;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k==0)
            ++z;
        else if (k>0)
            pos.push_back(k);
        else
            neg.push_back(k);
    }
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    for (int i=0;i<=min(5,sz(pos));++i)
        for (int j=0;i+j<=5&&j<=sz(neg);++j)
            if (z>=5-i-j)
            {
                //cout<<i<<" "<<j<<"\n";
                v.clear();
                for (int k=0;k<i;++k)
                    v.push_back(pos[k]);
                for (int k=0;k<j;++k)
                    v.push_back(neg[k]);
                for (int k=0;k<5-i-j;++k)
                    v.push_back(0);
                ans=max(ans,calc());
            }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    for (int i=0;i<=min(5,sz(pos));++i)
        for (int j=0;i+j<=5&&j<=sz(neg);++j)
            if (z>=5-i-j)
            {
                //cout<<i<<" "<<j<<"\n";
                v.clear();
                for (int k=0;k<i;++k)
                    v.push_back(pos[k]);
                for (int k=0;k<j;++k)
                    v.push_back(neg[k]);
                for (int k=0;k<5-i-j;++k)
                    v.push_back(0);
                ans=max(ans,calc());
            }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}