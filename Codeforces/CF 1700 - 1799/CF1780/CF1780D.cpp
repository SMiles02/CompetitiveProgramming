#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 30;
int n, m;
bool local = true;

void make_query(int x) {
    cout << "- " << x << endl;
    if (local) {
        m -= x;
        if (m < 0) {
            cout << "Subtracted too much" << endl;
            return -1;
        }
        return __builtin_popcount(m);
    }
    else {
        int new_cnt;
        cin >> new_cnt;
        return new_cnt;
    }
}

void solve() {
    int cnt, sm = 0;
    if (local) {
        cin >> n;
        m = n;
        cnt = __builtin_popcount(n);
    }
    else
        cin >> cnt;
    for (int i = 0; i < N; ++i) {
        int new_cnt = make_query(1 << i);
        sm += 1 << i
        if (new_cnt == 0) {
            cout << "! " << sm << endl;
            return;
        }
        if (new_cnt == cnt - 1) {

        }
        else {

        }
    }
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}