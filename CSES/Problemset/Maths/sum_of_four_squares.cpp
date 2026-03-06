#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
int min_prime[N];
vector<int> primes;

vector<array<int, 2>> get_factorisation(int n) {
    vector<array<int, 2>> factorisation;
    while (n > 1) {
        if (factorisation.empty() || factorisation.back()[0] != min_prime[n]) {
            factorisation.push_back({min_prime[n], 1});
        }
        else {
            ++factorisation.back()[1];
        }
        n /= min_prime[n];
    }
    return factorisation;
}

// Legendre's three-square theorem
bool check_three_squares(int n) {
    while (n % 4 == 0) n /= 4;
    return n % 8 != 7;
}

// Legendre's two-square theorem
bool check_two_squares(int n) {
    vector<array<int, 2>> factorisation = get_factorisation(n);
    for (auto [p, e] : factorisation) {
        if (p % 4 == 3 && e % 2 == 1) {
            return false;
        }
    }
    return true;
}

// Euler's four-square identity
array<int, 4> merge_four_squares(array<int, 4> x, array<int, 4> y) {
    return {x[0] * y[0] + x[1] * y[1] + x[2] * y[2] + x[3] * y[3],
            abs(x[0] * y[1] - x[1] * y[0] + x[2] * y[3] - x[3] * y[2]),
            abs(x[0] * y[2] - x[1] * y[3] - x[2] * y[0] + x[3] * y[1]),
            abs(x[0] * y[3] + x[1] * y[2] - x[2] * y[1] - x[3] * y[0])};
}

array<int, 2> get_two_squares(int n) {
    vector<array<int, 2>> factorisation = get_factorisation(n);
    int square_divisor = 1;
    for (auto [p, e] : factorisation) {
        if (e == 1) continue;
        if (e % 2 == 0) {
            for (int i = 1; i < e; i += 2) {
                square_divisor *= p;
                n /= p;
                n /= p;
            }
        }
        else {
            for (int i = 2; i < e; i += 2) {
                square_divisor *= p;
                n /= p;
                n /= p;
            }
        }
    }
    int s = sqrt(n);
    for (int i = s; i >= 0; --i) {
        int j = sqrt(n - i * i);
        if (i * i + j * j == n) return {square_divisor * i, square_divisor * j};
    }
    assert(false);
}

array<int, 3> get_three_squares(int n) {
    int s = sqrt(n);
    for (int i = s; i >= 0; --i) {
        if (check_two_squares(n - i * i)) {
            array<int, 2> tmp = get_two_squares(n - i * i);
            return {tmp[0], tmp[1], i};
        }
    }
    assert(false);
}

array<int, 4> get_four_square_p(int p) {
    int s = sqrt(p);
    for (int i = s; i >= 0; --i) {
        if (check_three_squares(p - i * i)) {
            array<int, 3> tmp = get_three_squares(p - i * i);
            return {tmp[0], tmp[1], tmp[2], i};
        }
    }
    assert(false);
}

array<int, 4> get_four_square_pe(int p, int e) {
    array<int, 4> cur, one;
    cur = one = get_four_square_p(p);
    for (int i = 1; i < e; ++i) cur = merge_four_squares(cur, one);
    return cur;
}

void solve() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0 0 0 0\n";
        return;
    }
    if (n == 1) {
        cout << "1 0 0 0\n";
        return;
    }
    vector<array<int, 2>> factorisation = get_factorisation(n);
    array<int, 4> ans = get_four_square_pe(factorisation[0][0], factorisation[0][1]);
    for (int i = 1; i < factorisation.size(); ++i) {
        ans = merge_four_squares(ans, get_four_square_pe(factorisation[i][0], factorisation[i][1]));
    }
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= min_prime[i] && i * primes[j] < N; ++j) {
            min_prime[i * primes[j]] = primes[j];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}