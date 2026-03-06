#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int p[N];
long long f[N];
bitset<N> done;

void build_permutation(int n, int i, long long k) {
    if (i == n + 1) {
        cout << "\n";
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (done[j]) continue;
        if (k <= f[n - i]) {
            cout << j << " ";
            done[j] = 1;
            build_permutation(n, i + 1, k);
        }
        k -= f[n - i];
    }
}

long long find_permutation(int n, int i) {
    if (i == n + 1) {
        return 1;
    }
    long long pos = 0;
    for (int j = 1; j <= n; ++j) {
        if (done[j]) continue;
        if (j != p[i]) {
            pos += f[n - i];
            continue;
        }
        done[j] = 1;
        return pos + find_permutation(n, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i;
    }
    int q, t, n;
    cin >> q;
    while (q--) {
        cin >> t >> n;
        if (t == 1) {
            long long k;
            cin >> k;
            for (int i = 1; i <= n; ++i) {
                done[i] = 0;
            }
            build_permutation(n, 1, k);
        }
        else {
            for (int i = 1; i <= n; ++i) {
                cin >> p[i];
                done[i] = 0;
            }
            cout << find_permutation(n, 1) << "\n";
        }
    }
    return 0;
}