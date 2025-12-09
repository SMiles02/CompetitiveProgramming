#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k * k < n)
            cout << "IMPOSSIBLE";
        else
            for (int i = 0; i <= n; i += k)
                for (int j = min(i + k, n); j > i; --j)
                    cout << j << " ";
        cout << "\n";
    }
}