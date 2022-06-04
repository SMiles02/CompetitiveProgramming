// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
int n, col[N], ct[2], w[N];
vector<int> e[N];

void dfs(int c, int p, int x) {
    col[c] = x;
    ++ct[x];
    for (int i : e[c])
        if (i != p)
            dfs(i, c, x ^ 1);
}

vector<ll> build(int trg) {
    vector<ll> v(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (col[i] == trg)
            v[i + 1] = sz(e[i]);
        else
            v[i + 1] = 1;
        v[1] += v[i + 1];
    }
    for (int i = 1; i <= n; ++i) {
        ll nSum = 0;
        for (int j : e[i])
            nSum += v[j + 1];
        if (v[i + 1] == nSum)
            ++v[0];
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> n;
    ct[0] = ct[1] = 0;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 0);
    vector<ll> v = build(0), w = build(1);
    if (w[0] > v[0] || (v[0] == w[0] && w[1] < v[1]))
        swap(v, w);
    cout << v[0] << " " << v[1] << "\n";
    for (int i = 2; i < n + 2; ++i)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}