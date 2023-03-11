#include <bits/stdc++.h>
using namespace std;

const int D = 30;
int basis[D], sz;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        k = p[i] ^= p[i - 1];
        for (int j = 0; j < D; ++j)
            if ((1 << j) & k) {
                if (!basis[j]) {
                    basis[j] = k;
                    ++sz;
                    break;
                }
                k ^= basis[j];
            }
    }
    if (p[n] == 0)
        sz = -1;
    cout << sz;
    return 0;
}