#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 1000;
bitset<N> is_comp;
vector<int> primes;

bool is_prime(ll n) {
    for (int i = 0; i < primes.size() && 1LL * primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    while (!is_prime(++n)) {}
    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i) {
        if (!is_comp[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < N; j += i) {
                is_comp[j] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}