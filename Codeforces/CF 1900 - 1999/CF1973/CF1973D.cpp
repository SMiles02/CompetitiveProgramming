#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;
bool local = true;
int n, k, a[N];

int make_query(int l, int x) {
    cout << "? " << l << " " << x << endl;
    if (local) {
        int maxi = 0;
        for (int i = l; i <= n; ++i) {
            maxi = max(maxi, a[i]);
            if (maxi * (i - l + 1) == x) {
                return i;
            }
        }
        return n + 1;
    }
    int qv;
    cin >> qv;
    return qv;
}

void print_answer(int ans) {
    cout << "! " << ans << endl;
    if (local) {
        return;
    }
    int correct;
    cin >> correct;
    if (correct == -1) {
        cerr << "idiot" << endl;
    }
}

void solve() {
    cin >> n >> k;
    if (local) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
    }
    // find the maximum
    int m = n;
    while (m > 1 && make_query(1, n * m) == n + 1) {
        --m;
    }
    cerr << "Maximum is " << m << endl;
    if (k == 1) {
        print_answer(n * m);
        return;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}