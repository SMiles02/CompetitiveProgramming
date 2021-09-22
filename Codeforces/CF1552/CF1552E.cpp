//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,l,r;
    cin>>n>>k;
    vector<vector<int>> v(n+1);
    for (int i=1;i<=n*k;++i)
    {
        cin>>x;
        v[x].push_back(i);
    }
    for (int i=1;i<=n;++i)
    {
        l=0;r=1e9;
        for (int j=1;j<k;++j)
            if (v[i][j]-v[i][j-1]<r-l)
            {
                l=v[i][j-1];
                r=v[i][j];
            }
        cout<<l<<" "<<r<<"\n";
    }
    return 0;
}