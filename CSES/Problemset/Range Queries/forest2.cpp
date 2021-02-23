#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n,m,rtn;
    vector<vector<int>> bit;
    BIT(int n, int m) : n(n), m(m), bit(n+1,vector<int> (m+1,0)) {}
    void update(int x, int y, int d) {
        for (int i=x;i<=n;i+=i&-i)
            for (int j=y;j<=m;j+=j&-j)
                bit[i][j]+=d;
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
};

bitset<1000> a[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,w,x,y,z;
    cin>>n>>q;
    char c;
    BIT bit(n,n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            cin>>c;
            if (c=='*')
            {
                a[i][j]=1;
                bit.update(i,j,1);
            }
        }
    while (q--)
    {
        cin>>t>>w>>x;
        if (t==1)
        {
            if (a[w][x])
            {
                a[w][x]=0;
                bit.update(w,x,-1);
            }
            else
            {
                a[w][x]=1;
                bit.update(w,x,1);
            }
        }
        else
        {
            cin>>y>>z;
            cout<<bit.query(w,x,y,z)<<"\n";
        }
    }
    return 0;
}