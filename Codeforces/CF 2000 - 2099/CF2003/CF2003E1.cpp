#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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