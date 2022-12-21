#include <bits/stdc++.h>
using namespace std;

const int N = 3162, INF = 1e9;
bitset<N> sieve;
vector<int> v;

int check(int x, int z) {
    return (z - (x % z)) % z;
}

void solve() {
    int x, y, z, ans = INF;
    cin >> x >> y;
    z = y - x;
    for (int i : v)
        if (z % i == 0) {
            while (z % i == 0)
                z /= i;
            ans = min(ans, check(x, i));
        }
    if (z > 1)
        ans = min(ans, check(x, z));
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i)
        if (sieve[i] == 0) {
            v.push_back(i);
            for (int j = i * 2; j < N; j += i)
                sieve[j] = 1;
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}