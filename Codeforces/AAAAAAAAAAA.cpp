#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6, M = 5e5;
int w[N + 1];

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << N << " " << M << "\n";
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    shuffle(v.begin(), v.end(), rng);
    for (int i = 0; i < M; ++i)
        ++w[v[i * 2 + get_rand(0, 1)]];
    for (int i = 1; i <= N; ++i) {
        if (w[i] == 0)
            w[i] += get_rand(2, 3);
        cout << w[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < M; ++i)
        cout << v[i * 2] << " " << v[i * 2 + 1] << "\n";
    return 0;
}