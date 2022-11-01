#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][i];
        for (int j = 1; j < n; ++j)
            a[i][(j + i) % n] = (a[i][(j + i - 1) % n] + i) % n;
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}