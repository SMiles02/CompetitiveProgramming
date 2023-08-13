#include <bits/stdc++.h>
using namespace std;

int n;

void print(int x) {
    if (n >= x) {
        cout << x << " ";
    }
}

void solve() {
    cin >> n;
    print(5);
    for (int i = n - (n & 1); i >= 6; i -= 2) {
        print(i);
    }
    print(2);
    print(1);
    for (int i = 7; i <= n; i += 2) {
        print(i);
    }
    print(4);
    print(3);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}