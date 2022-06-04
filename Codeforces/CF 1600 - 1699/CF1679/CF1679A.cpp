#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, y;
    cin >> n;
    if ((n & 1) || n == 2)
        cout << "-1\n";
    else if (n == 4)
        cout << "1 1\n";
    else {
        if (n % 6 == 0)
            x = n / 6;
        else if (n % 6 == 2)
            x = (n - 8) / 6 + 2;
        else
            x = (n - 4) / 6 + 1;
        if (n % 4 == 0)
            y = n / 4;
        else
            y = (n - 6) / 4 + 1;
        cout << x << " " << y << "\n"; 
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}