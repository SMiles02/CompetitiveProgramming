#include <bits/stdc++.h>
using namespace std;

int d[10], dC;
set<int> p, np;

bool is_prime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void rec(int done, int cur) {
    if (done == dC) {
        if (is_prime(cur))
            p.insert(cur);
        else
            np.insert(cur);
        return;
    }
    for (int i = 0; i < 10; ++i)
        if (d[i] > 0) {
            --d[i];
            rec(done + 1, cur * 10 + i);
            ++d[i];
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t >> n;
    while (n > 0) {
        ++dC;
        ++d[n % 10];
        n /= 10;
    }
    rec(0, 0);
    if (t == 0)
        cout << p.size();
    else if (np.empty())
        cout << 1;
    else
        cout << 0;
    return 0;
}