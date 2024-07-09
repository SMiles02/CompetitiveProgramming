#include <bits/stdc++.h>
using namespace std;

vector<int> sorted(vector<int> v) {
    sort(v.begin(), v.end());
    return v;
}

bool all_unique(vector<int> v) {
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            return false;
        }
    }
    return true;
}

long long count_inversions(vector<int>& v, int l = -1, int r = -1) {
    if (l == -1) {
        l = 0;
        r = (int)v.size() - 1;
    }
    if (l == r) {
        return 0;
    }
    vector<int> tmp(r - l + 1);
    int x = l, y = l + (r - l) / 2 + 1;
    long long inv = count_inversions(v, l, l + (r - l) / 2) + count_inversions(v, l + (r - l) / 2 + 1, r);
    for (int &i : tmp) {
        if (x == l + (r - l) / 2 + 1) {
            i = v[y++];
        }
        else if (y == r + 1) {
            i = v[x++];
        }
        else if (v[y] < v[x]) {
            i = v[y++];
            inv += l + (r - l) / 2 + 1 - x;
        }
        else {
            i = v[x++];
        }
    }
    for (int i = l; i <= r; ++i) {
        v[i] = tmp[i - l];
    }
    return inv;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    if (sorted(v) != sorted(w)) {
        cout << "NO\n";
    }
    else if (!all_unique(v) || (count_inversions(v) & 1) == (count_inversions(w) & 1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}