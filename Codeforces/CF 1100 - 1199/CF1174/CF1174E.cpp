#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e6 + 1;
int f[N], mx[N], cnt[N], min_prime[N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}
void build_sieve() {
    vector<int> pr;
    for (int i = 2; i < N; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < sz(pr) && pr[j] <= min_prime[i] && i * pr[j] < N; ++j)
            min_prime[i * pr[j]] = pr[j];
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    build_sieve();
    int n;
    cin >> n;
    for (int i = 2; i <= )
    return 0;
}