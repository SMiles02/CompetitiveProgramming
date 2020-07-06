#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,cur,point;
    cin>>n>>m>>k;
    ll ans=0;
    int a[n];
    vector<int> v={-1000000001};
    vector<int> ansList;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    point=n-(m*k);
    cur=0;
    for (int i=0;i<n;++i)
    {
        if (v[point]==a[i])
        {
            --point;
        }
        else if (v[point]<a[i])
        {
            ++cur;
            ans+=a[i];
            if (cur==m)
            {
                ansList.push_back(i+1);
                cur=0;
            }
        }
    }
    cout<<ans<<"\n";
    for (int i=0;i<sz(ansList)-1;++i) cout<<ansList[i]<<" ";
    return 0;
}