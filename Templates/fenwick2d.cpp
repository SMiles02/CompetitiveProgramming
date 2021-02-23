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
    int n,m;
    //BIT bit(n,m);
    //bit.update(i,j,d);
    //bit.query(x1,y1,x2,y2);
    return 0;
}