#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    int x = 1, y = 1000;
    vector<int> v;
    while (n > 2) {
        if (n & 1) {
            v.push_back(x++);
            --n;
        }
        else {
            v.push_back(y--);
            n /= 2;
        }
    }
    cout << v.size() + 1 << "\n500 ";
    while (!v.empty()) {
        cout << v.back() << " ";
        v.pop_back();
    }
    cout << "\n";
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