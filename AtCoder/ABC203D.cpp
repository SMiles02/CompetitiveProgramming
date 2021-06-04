#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n,m,rtn;
    vector<vector<int>> bit;
    BIT(int n, int m) : n(n), m(m), bit(n+1,vector<int> (m+1,0)) {}
    void update(int x, int y) {
        for (int i=x;i<=n;i+=i&-i)
            for (int j=y;j<=m;j+=j&-j)
                ++bit[i][j];
    }
    int query(int x, int y) {
        rtn=0;
        for (int i=x;i;i-=i&-i)
            for (int j=y;j;j-=j&-j)
                rtn+=bit[i][j];
        return rtn;
    }
    int query(int a, int b, int c, int d) {
        return query(c,d) - query(a-1,d) - query(c,b-1) + query(a-1,b-1);
    }
    void clear()
    {
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                bit[i][j]=0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,l=0,r=1e9,m;
    cin>>n>>k;
    if (k&1)
        x=(k*k)/2+1;
    else
        x=(k*k)/2;
    BIT bit(n,n);
    int a[n+1][n+1];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    while (l<r)
    {
        m=l+(r-l)/2;
        bit.clear();
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (a[i][j]<=m)
                    bit.update(i,j);
        bool ok=0;
        for (int i=k;i<=n&&!ok;++i)
            for (int j=k;j<=n;++j)
                if (bit.query(i-k+1,j-k+1,i,j)>=x)
                {
                    ok=1;
                    break;
                }
        //cout<<m<<": "<<ok<<"\n";      
        if (ok)
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}