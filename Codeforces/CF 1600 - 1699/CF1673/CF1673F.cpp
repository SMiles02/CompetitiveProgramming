#include <bits/stdc++.h>
using namespace std;

const int N = 32;
int a[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 10; ++i) {
        if (i & 1) {
            for (int j = 0; j < (1 << (i / 2 + 1)); ++j)
                for (int k = (1 << (i / 2)); k < (1 << (i / 2 + 1)); ++k)
                    a[j][k] = a[j][(1 << (i / 2 + 1)) - k - 1] ^ (1 << i);
        }
        else {
            for (int j = (1 << (i / 2)); j < (1 << (i / 2 + 1)); ++j)
                for (int k = 0; k < (1 << (i / 2)); ++k)
                    a[j][k] = a[(1 << (i / 2 + 1)) - j - 1][k] ^ (1 << i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j)
            cout << (a[i][j - 1] ^ a[i][j]) << " ";
        cout << endl;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (a[i - 1][j] ^ a[i][j]) << " ";
        cout << endl;
    }
    int q, cur = 0, x;
    array<int, 2> v[N * N];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            v[a[i][j]] = {i + 1, j + 1};
    cin >> q;
    while (q--) {
        cin >> x;
        cur ^= x;
        cout << v[cur][0] << " " << v[cur][1] << endl;
    }
    return 0;
}