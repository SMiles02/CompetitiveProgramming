#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << "Division ";
    if (n < 1400)
        cout << 4;
    else if (n < 1600)
        cout << 3;
    else if (n < 1900)
        cout << 2;
    else
        cout << 1;
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