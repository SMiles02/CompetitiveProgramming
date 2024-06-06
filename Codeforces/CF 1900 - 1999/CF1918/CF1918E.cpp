#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int make_query(int i) {
    cout << "? " << i << endl;
    char c;
    cin >> c;
    if (c == '>') {
        return 1;
    }
    if (c == '<') {
        return -1;
    }
    return 0;
}

void solve() {
    int n, cur;
    array<int, 2>
    cin >> n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}