#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e6 + 3, B = 3, MOD = 1e9 + 7;
array<int, B> bases[N], inverse[2];

array<int, B> add(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i) {
        a[i] += b[i];
        if (a[i] >= MOD)
            a[i] -= MOD;
    }
    return a;
}

array<int, B> add(array<int, B> a, int x) {
    for (int i = 0; i < B; ++i) {
        a[i] += x;
        if (a[i] >= MOD)
            a[i] -= MOD;
    }
    return a;
}
 
array<int, B> sub(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i) {
        a[i] -= b[i];
        if (a[i] < 0)
            a[i] += MOD;
    }
    return a;
}

array<int, B> sub(array<int, B> a, int x) {
    for (int i = 0; i < B; ++i) {
        a[i] -= x;
        if (a[i] < 0)
            a[i] += MOD;
    }
    return a;
}
 
array<int, B> mul(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i)
        a[i] = (1LL * a[i] * b[i]) % MOD;
    return a;
}

array<int, B> mul(array<int, B> a, int x) {
    for (int i = 0; i < B; ++i) {
        a[i] = (1LL * a[i] * x) % MOD;
    }
    return a;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int get_hash_val(int x, vector<int>& v, vector<int>& w) {
    int l = 0, r = v.size(), m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (v[m] < x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return w[l];
}

bool equals(array<int, B>& a, array<int, B>& b) {
    for (int i = 0; i < B; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void print(array<int, B> a) {
    for (int i = 0; i < B; ++i) {
        cerr << a[i] << " ";
    }
    cerr << "\n";
}

void push_to_back(deque<int>& a, deque<int>& b) {
    int af = a.front(), bf = b.front();
    a.pop_front();
    b.pop_front();
    a.push_back(bf);
    b.push_back(af);
}

void solve() {
    int n, cnt = 0;
    cin >> n;
    deque<int> a(n), b(n);
    vector<int> v(n * 2), w(n * 2), rev_hash = {-1};
    array<int, B> x, y;
    for (int i = 0; i < B; ++i) {
        x[i] = y[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        v[i + n] = b[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * 2; ++i) {
        if (i == 0 || v[i] != v[i - 1]) {
            w[i] = rev_hash.size();
            rev_hash.push_back(v[i]);
        }
        else {
            w[i] = w[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] = get_hash_val(a[i], v, w);
        x = add(x, mul(bases[i], a[i]));
    }
    for (int i = 0; i < n; ++i) {
        b[n - i - 1] = get_hash_val(b[n - i - 1], v, w);
        y = add(y, mul(bases[i], b[n - i - 1]));
    }
    for (int i = 0; i < n / 2; ++i) {
        cnt += a[i] < b[i];
    }
    for (int i = 0; i <= n * 2; ++i) {
        // cerr << i << ": " << cnt << " " << x[0] << " " << x[1] << " " << y[0] << " " << y[1] << "\n";
        if (cnt == n / 2 && equals(x, y)) {
            cout << i << "\n";
            return;
        }
        x = sub(x, mul(bases[0], a[0]));
        y = sub(y, mul(bases[n - 1], b[0]));
        x = mul(x, inverse[1]);
        y = mul(y, bases[1]);
        x = add(x, mul(bases[n - 1], b[0]));
        y = add(y, mul(bases[0], a[0]));
        cnt -= a[0] < b[0];
        cnt += a[n / 2] < b[n / 2];
        push_to_back(a, b);
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < B; ++i) {
        bases[0][i] = 1;
        bases[1][i] = get_rand(3e6, 5e6);
        // bases[1][i] = 10;
        inverse[1][i] = 1;
        inverse[1][i] = binpow(bases[1][i], MOD - 2);
    }
    for (int i = 2; i < N; ++i) {
        bases[i] = mul(bases[i - 1], bases[1]);
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}