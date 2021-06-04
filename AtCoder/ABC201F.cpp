#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,l,r,m;
    cin>>n;
    int p[n+1];
    p[0]=0;
    vector<array<int,4>> v(n+1);
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v[k][0]=i;
    }
    v[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>v[i][1]>>v[i][2]>>v[i][3];
        v[i][2]=min(v[i][2],v[i][1]);
        v[i][3]=min(v[i][3],v[i][1]);
        p[i]=p[i-1]+(v[i][0]>v[i-1][0]);
    }

    return 0;
}