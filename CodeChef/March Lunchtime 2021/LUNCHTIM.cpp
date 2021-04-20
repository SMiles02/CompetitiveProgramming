#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 1e9+7;

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1)
    {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }

    int find(int i)
    {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);
        if (i^j)
        {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};
 
void solve()
{
    int n;
    cin>>n;
    DSU dsu(n);
    stack<int> s;
    s.push(0); 
    int a[n+1];
    a[0]=INF;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        while (a[s.top()]<a[i])
            s.pop();
        if (a[s.top()]==a[i])
            dsu.unite(s.top(),i);
        s.push(i);
    }
    for (int i=1;i<=n;++i)
        cout<<dsu.rk[dsu.find(i)]-1<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}