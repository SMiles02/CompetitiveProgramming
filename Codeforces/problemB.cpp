#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+69, INF=1e9+4;
int a[mn],segTree[2][5*mn];
//0-min 1-max
vector<int> nun = {INF,-INF};

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[0][i]=segTree[1][i]=a[l];
        return;
    }
    int m=l+(r-l)/2;
    build(i*2+1,l,m);
    build(i*2+2,m+1,r);
    segTree[0][i]=min(segTree[0][2*i+1],segTree[0][2*i+2]);
    segTree[1][i]=max(segTree[1][2*i+1],segTree[1][2*i+2]);
}

int query(int j, int i, int cL, int cR, int l, int r)
{
    //cout<<"! "<<i<<" "<<cL<<" "<<cR<<" "<<l<<" "<<r<<"\n";
    if (l<=cL&&cR<=r)
    {
        //cout<<"we good\n";
        //cout<<"sending "<<segTree[j][i]<<"\n";
        return segTree[j][i];
    }
    if (r<cL||cR<l)
    {
        //cout<<"nothing\n";
        return nun[j];
    }
    int m=cL+(cR-cL)/2;
    if (j==1)
        return max(query(j,i*2+1,cL,m,l,r),query(j,i*2+2,m+1,cR,l,r));
    else
        return min(query(j,i*2+1,cL,m,l,r),query(j,i*2+2,m+1,cR,l,r));
}

int solve(vector<int>& nums, vector<vector<int>>& queries) {
    int n=sz(nums),ans=0;
    if (n<2)
        return sz(queries);
    for (int i=0;i+1<n;++i)
        a[i]=nums[i+1]-nums[i];
    build(0,0,n-2);
    for (auto i : queries)
    {
        if (i[0]==i[1])
            ++ans;
        else if (query(0,0,0,n-2,i[0],i[1]-1)==query(1,0,0,n-2,i[0],i[1]-1))
        {
            //cout<<"yay\n";
            cout<<query(0,0,0,n-2,i[0],i[1]-1)<<" "<<query(1,0,0,n-2,i[0],i[1]-1)<<"\n";
            ++ans;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r;
    cin>>n>>q;
    vector<int> v(n);
    vector<vector<int>> queries(q);
    for (int i=0;i<n;++i)
        cin>>v[i];
    for (int i=0;i<q;++i)
    {
        cin>>l>>r;
        queries[i]={l,r};
    }
    cout<<solve(v,queries);
    return 0;
}