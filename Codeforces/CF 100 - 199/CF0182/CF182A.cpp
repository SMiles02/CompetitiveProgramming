#include <bits/stdc++.h>
using namespace std;

double dist(int x, int y) {
    return sqrt(1LL * x * x + 1LL * y * y);
}

double check_distance(int x, int y, int z) {
    if (x < y)
        return y - x;
    else if (z < x)
        return x - z;
    return 0;
}

double check_distance(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y) {
    if (b_x == c_x)
        return dist(abs(a_x - b_x), check_distance(a_y, b_y, c_y));
    return dist(abs(a_y - b_y), check_distance(a_x, b_x, c_x));
}

const int N = 1002, INF = 1e9;
int d[N], t[N][4];
double e[N][N];
bitset<N> dn;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, n, x;
    double ans = INF;
    cin >> a >> b;
    cin >> t[0][0] >> t[0][1];
    t[0][2] = t[0][0];
    t[0][3] = t[0][1];
    cin >> t[1][0] >> t[1][1];
    t[1][2] = t[1][0];
    t[1][3] = t[1][1];
    cin >> n;
    for (int i = 2; i <= n + 1; ++i) {
        for (int j = 0; j < 4; ++j)
            cin >> t[i][j];
        for (int j = 0; j < 2; ++j)
            if (t[i][j] > t[i][j + 2])
                swap(t[i][j], t[i][j + 2]);
    }
    for (int i = 0; i <= n + 1; ++i)
        for (int j = i; j <= n + 1; ++j) {
            e[i][j] = INF;
            e[i][j] = min(e[i][j], check_distance(t[i][0], t[i][1], t[j][0], t[j][1], t[j][2], t[j][3]));
            e[i][j] = min(e[i][j], check_distance(t[i][2], t[i][3], t[j][0], t[j][1], t[j][2], t[j][3]));
            e[i][j] = min(e[i][j], check_distance(t[j][0], t[j][1], t[i][0], t[i][1], t[i][2], t[i][3]));
            e[i][j] = min(e[i][j], check_distance(t[j][2], t[j][3], t[i][0], t[i][1], t[i][2], t[i][3]));
            e[j][i] = e[i][j];
        }
    queue<int> q;
    q.push(0);
    dn[0] = 1;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 2; i <= n + 1; ++i)
            if (e[x][i] <= a && !dn[i]) {
                dn[i] = 1;
                d[i] = d[x] + 1;
                q.push(i);
            }
        if (e[x][1] <= a)
            ans = min(ans, e[x][1] + (a + b) * d[x]);
    }
    if (ans == INF)
        cout << -1;
    else
        cout << fixed << setprecision(13) << ans;
    return 0;
}