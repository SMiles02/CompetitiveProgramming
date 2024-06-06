#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a[N];
vector<array<int, 2>> ans;

void op(int l, int r) {
    for (int x = 0; x < 20; ++x) {
        bool ok = false;
        for (int i = l; i <= r; ++i) {
            ok |= a[i] == x;
        }
        if (!ok) {
            for (int i = l; i <= r; ++i) {
                a[i] = x;
            }
            return;
        }
    }
}

void submagic(int l, int r) { // a[l, r] = r - l
    if (l == r) {
        if (a[l] == 0) {
            return;
        }
        op(l, l);
        a[l] = 0
        return;
    }
    for (int i = l; i < r; ++i) {
        submagic(l, i);
    }
    
}

void magic(int l, int r) { // a[l, r] = r - l + 1
    for (int i = r; i >= l; --i) {
        submagic(l, i);
    }
    op(l, r);
}

void solve(int l, int r) {
    if (l > r) {
        return;
    }
    int id = l, sm = a[l];
    for (int i = l + 1; i <= r; ++i) {
        sm += a[i];
        if (a[i] > a[id]) {
            id = i;
        }
    }
    if (sm > (r - l + 1) * (r - l + 1)) {
        rec(l, id - 1);
        rec(id + 1, r);
        return;
    }
    magic(l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    solve(1, n);
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += a[i];
    }
    cout << s << " " << ans.size() << "\n";
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << "\n";
    }
    return 0;
}