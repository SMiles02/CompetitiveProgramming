#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct bfs {
    const int INF = 1e9;
    int n;
    vector<vector<int>> edges;
    bfs(int n) : n(n), edges(n + 1) {}
    void add_directed_edge(int x, int y) {
        edges[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> run_bfs(int source) {
        vector<int> p(n + 1, -1);
        queue<int> q;
        p[source] = source;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            // cerr << "visiting " << x << endl;
            q.pop();
            for (int i : edges[x])
                if (p[i] == -1) {
                    // cerr << x << " -> " << i << endl;
                    p[i] = x;
                    q.push(i);
                }
        }
        return p;
    }
};

const int N = 3e5 + 1;
int pf[N], pn[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, s, t, k, cnt = 0;
    cin >> n;
    bfs graph(N * 2);
    for (int i = 2; i < N; ++i) {
        if (pf[i] != 0) {
            continue;
        }
        pn[i] = ++cnt;
        for (int j = i; j < N; j += i) {
            pf[j] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        while (k > 1) {
            graph.add_undirected_edge(i, n + pn[pf[k]]);
            k /= pf[k];
        }
    }
    cin >> s >> t;
    vector<int> p = graph.run_bfs(t), ans = {s};
    if (p[s] == -1) {
        cout << "-1\n";
        return 0;
    }
    while (ans.back() != t) {
        ans.push_back(p[p[ans.back()]]);
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}