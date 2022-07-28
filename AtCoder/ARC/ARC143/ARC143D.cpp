#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+7;

bitset<N> dn, dnE;
vector<array<int, 2>> simplified_edges[N];
bitset<N> swapped;

void dfs(int c) {
    dn[c] = 1;
    for (auto i : simplified_edges[c])
        if (!dnE[i[1]]) {
            dnE[i[1]] = 1;
            if (dn[i[0]])
                swapped[i[1]] = 1;
            else
                dfs(i[0]);
        }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    for (int i = 0; i < m; ++i) {
        simplified_edges[a[i]].push_back({b[i], i});
        simplified_edges[b[i]].push_back({a[i], i});
    }
    for (int i = 1; i <= n; ++i)
        if (!dn[i])
            dfs(i);
    for (int i = 0; i < m; ++i)
        cout << swapped[i];
    return 0;
}