#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 1e6, N = 1e5;
const bool YES = 1;
int w[N + 1];
set<int> s[M + 1];
int v[M + 1][2];

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt", "w", stdout);
    cout << N << " " << M << "\n";
    int x, y;
    vector<int> a(M);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end(), rng);
    for (int i : a) {
        v[i][0] = get_rand(1, N);
        v[i][1] = v[i][0];
        while (v[i][0] == v[i][1])
            v[i][1] = get_rand(1, N);
        ++w[v[i][0]];
    }
    shuffle(a.begin(), a.end(), rng);
    if (!YES) {
        bool removed = false, added = false;
        for (int i = 1; i <= N; ++i)
            if (w[i]) {
                if (!removed) {
                    --w[i];
                    removed = true;
                }
                else if (!added) {
                    ++w[i];
                    added = true;
                }
            }
    }
    for (int i = 1; i <= N; ++i) {
        if (w[i] == 0)
            w[i] += get_rand(0, 1);
        cout << w[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= M; ++i) {
        if (get_rand(1, 2) == 1)
            swap(v[i][0], v[i][1]);
        cout << v[i][0] << " " << v[i][1] << "\n";
    }
    return 0;
}