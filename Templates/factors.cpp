#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;

const int N = 1e7+1;
int min_prime[N];
vector<array<int, 2>> factorisation;
  
void build_sieve() {
    vector<int> pr;
    for (int i=2; i<N; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j<sz(pr) && pr[j] <= min_prime[i] && i * pr[j] < N; ++j)
            min_prime[i * pr[j]] = pr[j];
    }
}

void rec(int pos, int cur) {
    if (pos == sz(factorisation)) {
        // cur is a factor
        // do what you want with it
        return;
    }
    int cur_mul = 1;
    for (int i = 0; i <= factorisation[pos][1]; ++i) {
        rec(pos + 1, cur * cur_mul);
        cur_mul *= factorisation[pos][0];
    }
}

void get_factors(int num) {
    factorisation.clear();
    while (num > 1) {
        if (!factorisation.empty() && min_prime[num] == factorisation.back()[0])
            ++factorisation.back()[1];
        else
            factorisation.push_back({min_prime[num], 1});
        num /= min_prime[num];
    }
    rec(0, 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    build_sieve();
    get_factors(69);
    return 0;
}