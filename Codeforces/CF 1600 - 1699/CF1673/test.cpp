#include <bits/stdc++.h>
using namespace std;

int hsb(int x) {
    while (__builtin_popcount(x) > 1)
        x -= x & -x;
    return x;
}

const int N = 32;
int a[N][N];

void build(int xL, int xR, int yL, int yR, int c, int p, bool l, bool r, bool u, bool d) {
    if (xL == xR && yL == yR) {
        a[xL][yL] = c;
        return; 
    }
    int m;
    if (u) {
        if (yL < yR) {
            m = yL + (yR - yL) / 2;
            build(xL, xR, yL, m, c, p - 1, 0, 0, 1, 0);
            build(xL, xR, m + 1, yR, c ^ (1 << p), p - 1, 0, 0, 0, 1);
        }
        else {
            m = xL + (xR - xL) / 2;
            build(xL, m, yL, yR, c, p - 1, 1, 0, 0, 0);
            build(m + 1, xR, yL, yR, c ^ (1 << p), p - 1, 0, 1, 0, 0);
        }
    }
    else if (d) {
        if (yL < yR) {
            m = yL + (yR - yL) / 2;
            build(xL, xR, yL, m, c ^ (1 << p), p - 1, 0, 0, 1, 0);
            build(xL, xR, m + 1, yR, c, p - 1, 0, 0, 0, 1);
        }
        else {
            m = xL + (xR - xL) / 2;
            build(xL, m, yL, yR, c ^ (1 << p), p - 1, 1, 0, 0, 0);
            build(m + 1, xR, yL, yR, c, p - 1, 0, 1, 0, 0);
        }
    }
    else if (l) {
        m = xL + (xR - xL) / 2;
        build(xL, m, yL, yR, c, p - 1, 1, 0, 0, 0);
        build(m + 1, xR, yL, yR, c ^ (1 << p), p - 1, 0, 1, 0, 0);
    }
    else {
        m = xL + (xR - xL) / 2;
        build(xL, m, yL, yR, c ^ (1 << p), p - 1, 1, 0, 0, 0);
        build(m + 1, xR, yL, yR, c, p - 1, 0, 1, 0, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 32, ans = 0;
    // build(0, 31, 0, 31, 0, 9, 0, 0, 1, 0);
    a[0][0] = 0;
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
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if (i + 1 < N)
                ans += (a[i][j] ^ a[i + 1][j]);
            if (j + 1 < N)
                ans += (a[i][j] ^ a[i][j + 1]);
        }
    cout << ans;
    return 0;
}