#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 41, ITERATIONS = 9000000, X = 2e9;
int n, m, c[M], ans, cur_cost;
bitset<M> cur, mandatory, e[M];
double t = 50;

int rnd_range(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

double rnd() {
    return double(rng() % X) / X;
}

void delete_colour() {
    vector<int> v;
    for (int i = 1; i <= m; ++i)
        if (cur[i] && !mandatory[i]) {
            bool ok = true;
            for (int j = 1; j <= m; ++j)
                if (e[i][j] && !cur[j]) {
                    ok = false;
                    break;
                }
            if (ok)
                v.push_back(i);
        }
    if (v.empty())
        return;
    int removed_colour = v[rnd_range(0, v.size() - 1)];
    cur_cost -= c[removed_colour];
    cur[removed_colour] = 0;
    ans = min(ans, cur_cost);
}

void add_colour() {
    vector<int> v;
    for (int i = 1; i <= m; ++i)
        if (!cur[i])
            v.push_back(i);
    if (v.empty())
        return;
    int new_colour = v[rnd_range(0, v.size() - 1)];
    if (rnd() < exp((c[new_colour] - cur_cost) / t)) {
        cur_cost += c[new_colour];
        cur[new_colour] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    mandatory[a[0]] = mandatory[a[n - 1]] = 1;
    for (int i = 2; i + 1 < n; ++i) {
        if (a[i] == a[i - 1])
            mandatory[a[i]] = 1;
        else
            e[a[i]][a[i - 1]] = e[a[i - 1]][a[i]] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
        cur_cost += c[i];
        cur[i] = 1;
    }
    ans = cur_cost;
    double mpl = pow((1e-5) / t, (double) 1 / ITERATIONS);
    for (int i = 0; i < ITERATIONS; ++i) {
        t *= mpl;
        if (rnd_range(0, 1))
            delete_colour();
        else
            add_colour();
    }
    cout << ans;
    return 0;
}