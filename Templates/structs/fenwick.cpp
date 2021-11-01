#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x-1); }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    //BIT bit(n);
    //bit.update(i,d);
    //bit.query(l,r);
    return 0;
}