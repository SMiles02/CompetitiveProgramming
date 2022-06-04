#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1) {
        for (int i = 0; i <= n; ++i)
            pt[i] = i;
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    DSU dsu(n);
    for (int i=0;i+1<n;++i)
        if (s[i]=='E')
            dsu.unite(i,i+1);
    if (s[n-1]=='E')
        dsu.unite(n-1,0);
    for (int i=0;i+1<n;++i)
        if (s[i]=='N'&&dsu.find(i)==dsu.find(i+1))
        {
            cout<<"NO\n";
            return;
        }
    if (s[n-1]=='N'&&dsu.find(n-1)==dsu.find(0))
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}