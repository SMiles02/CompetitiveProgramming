#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n, ans[N];
vector<array<int, 2>> e;

struct DSU {
    vector<int> pt;
    DSU(int n) : pt(n + 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j, int s) {
        i = find_set(i);
        j = find_set(j);
        if (max(ans[i], ans[j]) != s) {
            pt[i] = pt[j] = ++n;
            e.push_back({i, n});
            e.push_back({j, n});
            ans[n] = s;
        }
        else if (ans[i] > ans[j]) {
            pt[j] = i;
            e.push_back({j, i});
        }
        else if (ans[j] > ans[i]) {
            pt[i] = j;
            e.push_back({j, i});
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x;
    cin >> n;
    DSU dsu(n * 2);
    vector<array<int, 3>> a;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if (i == j)
                ans[i] = x;
            else
                a.push_back({x, i, j});
        }
    sort(a.begin(), a.end());
    for (auto i : a)
        dsu.unite(i[1], i[2], i[0]);
    cout << n << "\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n" << n << "\n";
    for (auto i : e)
        cout << i[0] << " " << i[1] << "\n";
    return 0;
}