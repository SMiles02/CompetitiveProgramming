#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 501, INF = 1e9;
int n, m, l, a, b, c, d, f[N][N];
array<int, 2> pos[N * N];
double t = 1000;
long double score, new_score;
bitset<N> grid[N];
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

double rnd() {
    return double(get_rand(0, INF)) / INF;
}

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

long double calc_score() {
    long double ret = 0;
    for (int i = 0; i < n; ++i) {
        long double mpl = 1;
        for (int j = 0; j < m; ++j)
            if (grid[i][j]) {
                long double nbr = mpl;
                for (int d = 0; d < 4; ++d)
                    if (ok(i + dx[d], j + dy[d]) && grid[i + dx[d]][j + dy[d]])
                        nbr *= 0.95;
                ret += nbr * f[i][j] * f[i][j] * f[i][j];
                mpl *= 0.8;
            }
    }
    return ret;
}

bool check_if_grid_valid() {
    int cur = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cur += grid[i][j];
    return cur == l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> l >> a >> b >> c >> d;
    vector<array<int, 2>> v;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            v.push_back({i, j});
            f[i][j] = a + b * i + c * i * i - d * j;
        }
    shuffle(v.begin(), v.end(), rng);
    for (int i = 0; i < l; ++i) {
        grid[v[i][0]][v[i][1]] = 1;
        pos[i] = {v[i][0], v[i][1]};
    }
    score = calc_score();
    int iterations = 3000;
    double mpl = pow(1e-5 / t, (double)1 / iterations);
    for (int iter = 0; iter < iterations; ++iter) {
        t *= mpl;
        int i = get_rand(0, l - 1), d = get_rand(0, 3);
        if (ok(pos[i][0] + dx[d], pos[i][1] + dy[d]) && grid[pos[i][0] + dx[d]][pos[i][1] + dy[d]] == 0) {
            grid[pos[i][0]][pos[i][1]] = 0;
            grid[pos[i][0] + dx[d]][pos[i][1] + dy[d]] = 1;
        }
        else
            continue;
        new_score = calc_score();
        if (new_score > score || rnd() < exp(double(new_score - score) / t)) {
            score = new_score;
            pos[i][0] += dx[d];
            pos[i][1] += dy[d];
        }
        else {
            grid[pos[i][0]][pos[i][1]] = 1;
            grid[pos[i][0] + dx[d]][pos[i][1] + dy[d]] = 0;
        }
        // if (!check_if_grid_valid())
        //     assert(0);
        // cerr << score << "\n";
    }
    cerr << score << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j])
                cout << "x";
            else
                cout << ".";
        }
        cout << "\n";
    }
    return 0;
}