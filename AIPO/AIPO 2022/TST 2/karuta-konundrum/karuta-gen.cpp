#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int N = 2e5, K = 17, MIN_Q = (N * 7) / 8, MAX_Q = N;
string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt", "w", stdout);
    cout << N << " " << K << "\n";
    string s(N, 'a');
    for (int i = 0; i < N; ++i)
        s[i] = alpha[get_rand(0, K - 1)];
    if (MAX_Q > 0) {
        int q = get_rand(MIN_Q, MAX_Q);
        vector<int> v(N);
        iota(v.begin(), v.end(), 0);
        shuffle(v.begin(), v.end(), rng);
        for (int i = 0; i < q; ++i)
            s[v[i]] = '?';
    }
    cout << s;
    return 0;
}