#include <bits/stdc++.h>
using namespace std;

// post-contest notes:
// - it's always optimal to take the cheapest pubs
// so just sort and do it???

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, b, ans = 0;
    cin >> n;
    cin >> b;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        if (a[i] <= b) {
            b -= a[i];
            ++ans;
        }
    cout << ans;
    return 0;
}