#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int sub(int a, int b) { return add(a,MOD-b); }

struct DSU
{
    int ans=0;
    vector<int> pt,rk,mx,mn;
    DSU(int n) : pt(n+1), rk(n+1, 1), mx(n+1), mn(n+1) {
        for (int i = 1; i <= n; ++i)
        {
            pt[i] = i;
            mx[i] = i;
            mn[i] = i;
            ans=add(ans,i-1);
        }
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void quickUnite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            ans=sub(ans,mul(rk[i],sub(mx[i],1)));
            ans=sub(ans,mul(rk[j],sub(mx[j],1)));
            pt[j] = i;
            rk[i] += rk[j];
            mx[i]=max(mx[i],mx[j]);
            mn[i]=min(mn[i],mn[j]);
            ans=add(ans,mul(rk[i],sub(mx[i],1)));
        }
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (mn[i] > mn[j])
                swap(i, j);
            for (int k=mx[i];k<mn[j];++k)
                quickUnite(k,k+1);
        }
    }
};

void solve()
{
    int n,m,tot=1,x,y;
    cin>>n>>m;
    DSU dsu(n);
    while (m--)
    {
        cin>>x>>y;
        dsu.unite(n+1-x,n+1-y);
        tot=mul(tot,dsu.ans);
    }
    cout<<tot<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}