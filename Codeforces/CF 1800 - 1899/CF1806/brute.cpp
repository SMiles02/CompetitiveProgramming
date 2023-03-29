#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 20, MN = -5, MX = 5;
int n, a[N];
bool ok;

void check_sub(int i, int p, int x, int s, int y) {
    if (i == n * 2) {
        if (p != s)
            ok = false;
        return;
    }
    if (x < n)
        check_sub(i + 1, p * a[i], x + 1, s, y);
    if (!ok)
        return;
    if (y < n)
        check_sub(i + 1, p, x, s + a[i], y + 1);
}

void check() {
    ok = true;
    check_sub(0, 1, 0, 0, 0);
    if (ok) {
        for (int j = 0; j < n * 2; ++j)
            cout << a[j] << " ";
        cout << endl;
    }
}

void rec(int i) {
    if (i == n * 2) {
        check();
        return;
    }
    for (int j = MN; j <= MX; ++j) {
        a[i] = j;
        rec(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rec(0);
    return 0;
}