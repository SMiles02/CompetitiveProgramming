#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll n,a,r,m;

ll binSearch(vector<int> v, int k)
{
    int x=0,y=n-1,z;
    ll ans=0;
    while (x<y&&v[x]<k&&v[y]>k)
    {
        z=min(k-v[x],v[y]-k);
        v[x]+=z;
        v[y]-=z;
        ans+=(m*z);
        if (v[x]==k)
            ++x;
        if (v[y]==k)
            --y;
    }
    for (int i=0;i<n;++i)
    {
        if (v[i]<k)
            ans+=(a*(k-v[i]));
        else
            ans+=(r*(v[i]-k));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k,left,right,mid;
    cin>>n>>a>>r>>m;
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v.push_back(k);
    }
    m=min(m,a+r);
    sort(v.begin(), v.end());
    if (binSearch(v,1)<binSearch(v,2))
    {
        cout<<binSearch(v,1)<<"\n";
        return 0;
    }
    left=2,right=1000000000;
    while (left<right)
    {
        mid=left+(right-left)/2+1;
        if (binSearch(v,mid-1)<binSearch(v,mid))
            right=mid-1;
        else
            left=mid;
    }
    cout<<binSearch(v,left);
    return 0;
}