#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[(n * (n - 1)) / 2];
    for (int i = 0; i < (n * (n - 1)) / 2; ++i) {
        cin >> a[i];
    }
    sort(a, a + (n * (n - 1)) / 2);
    for (int i = 0, x = n - 1; i < (n * (n - 1)) / 2; i += (x--)) {
        cout << a[i] << " ";
    }
    cout << a[(n * (n - 1)) / 2 - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}