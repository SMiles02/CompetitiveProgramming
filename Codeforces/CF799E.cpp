#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll INF = 1e17;
int a,b,c,d,n,m,k,x,y,z,f[200001];
vector<ll> v[4];

ll noGroup(int A)
{
    if (A<0)
        return v[0][0];
    if (A>a)
        return INF;
    return v[0][A];
}

ll arkady(int A, int B)
{
    int l=B,r=b,m;
    if (l>r)
        return INF*2;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (v[1][m-1]+noGroup(A-m+1)<v[1][m]+noGroup(A-m))
            r=m-1;
        else
            l=m;
    }
    return v[1][l]+noGroup(A-l);
}

ll masha(int A, int B, int C)
{
    int l=C,r=c,m;
    if (l>r)
        return INF*4;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (v[2][m-1]+arkady(A-m+1,B)<v[1][m]+arkady(A-m,B))
            r=m-1;
        else
            l=m;
    }
    return v[1][l]+arkady(A-l,B);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<4;++i)
        v[i].push_back(0);
    cin>>n>>m>>k;
    int arr[n+1];
    for (int i=1;i<=n;++i)
        cin>>arr[i];
    cin>>x;
    while (x--)
    {
        cin>>z;
        ++f[z];
    }
    cin>>x;
    while (x--)
    {
        cin>>z;
        f[z]+=2;
    }
    for (int i=1;i<=n;++i)
        v[f[i]].push_back(arr[i]);
    for (int i=0;i<4;++i)
        partial_sum(v[i].begin(), v[i].end(), v[i].begin());
    a=sz(v[0])-1;
    b=sz(v[1])-1;
    c=sz(v[2])-1;
    d=sz(v[3])-1;
    int l=0,r=min(d,k),m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (v[3][m-1]+masha(k-m+1,k-m+1,k-m+1)<v[3][m]+masha(k-m,k-m,k-m))
            r=m-1;
        else
            l=m;
    }
    if (v[3][l]+masha(k-m,))
    return 0;
}