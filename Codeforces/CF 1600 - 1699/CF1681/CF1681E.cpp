#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 7, L = 18;
const ll INF = 1e18;
int a[N][2][2], b[N][2][2];
ll up[N][L][2][2];

int d(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, x1, y1, x2, y2, layer;
    array<ll, 2> ans, newAns;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k) {
                cin >> a[i][j][k];
                b[i + 1][j][k] = a[i][j][k];
            }
        ++b[i + 1][0][0];
        ++b[i + 1][1][1];
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < L; ++j)
            for (int k = 0; k < 2; ++k)
                for (int l = 0; l < 2; ++l)
                    up[i][j][k][l] = INF;
    for (int i = n - 1; i > 0; --i) {
        for (int k = 0; k < 2; ++k) {
            up[i][0][k][k] = 1;
            up[i][0][k][1 - k] = d(a[i][0][0], a[i][0][1], a[i][1][0], a[i][1][1]) + 1;
        }
        for (int j = 1; i + (1 << j) <= n; ++j)
            for (int k = 0; k < 2; ++k)
                for (int l = 0; l < 2; ++l)
                    for (int m = 0; m < 2; ++m)
                        for (int o = 0; o < 2; ++o)
                            up[i][j][k][l] = min(up[i][j][k][l], up[i][j - 1][k][m] + up[i + (1 << (j - 1))][j - 1][o][l] + d(b[i + (1 << (j - 1))][m][0], b[i + (1 << (j - 1))][m][1], a[i + (1 << (j - 1))][o][0], a[i + (1 << (j - 1))][o][1]));
    }
    cin >> q;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (max(x1, y1) == max(x2, y2)) {
            cout << d(x1, y1, x2, y2) << "\n";
            continue;
        }
        if (max(x1, y1) > max(x2, y2)) {
            swap(x1, x2);
            swap(y1, y2);
        }
        layer = max(x1, y1);
        ans[0] = d(x1, y1, a[layer][0][0], a[layer][0][1]) + 1;
        ans[1] = d(x1, y1, a[layer][1][0], a[layer][1][1]) + 1;
        ++layer;
        for (int j = L - 1; j >= 0; --j)
            if (layer + (1 << j) <= max(x2, y2)) {
                newAns[0] = newAns[1] = INF;
                for (int m = 0; m < 2; ++m)
                    for (int k = 0; k < 2; ++k)
                        for (int l = 0; l < 2; ++l)
                            newAns[l] = min(newAns[l], ans[m] + up[layer][j][k][l] + d(b[layer][m][0], b[layer][m][1], a[layer][k][0], a[layer][k][1]));
                layer += (1 << j);
                swap(ans, newAns);
            }
        ans[0] += d(x2, y2, b[layer][0][0], b[layer][0][1]);
        ans[1] += d(x2, y2, b[layer][1][0], b[layer][1][1]);
        cout << min(ans[0], ans[1]) << "\n";
    }
    return 0;
}