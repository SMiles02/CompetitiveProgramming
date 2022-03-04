#include <bits/stdc++.h>
using namespace std;

int main() {
    // n <= 2 * 10^5
    // 10^9 ops / sec
    int n, k;
    cin >> n;
    bool exists[n + 1];
    // if exists[i] = true
    // then i is in a
    for (int i = 1; i <= n; ++i) // O(n)
        exists[i] = false;
    int a[n - 1];
    for (int i = 0; i < n - 1; ++i) { // O(n)
        cin >> a[i];
        exists[a[i]] = true;
    }
    for (int i = 1; i <= n; ++i) // O(n)
        if (exists[i] == false)
            cout << i;
    return 0;
}
// overall O(n)