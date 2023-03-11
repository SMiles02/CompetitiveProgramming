#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void print_ans(string s) {
    cerr << "Score in " + s + ": " + score;
    string file = "out/file_" + s + ".out";
    freopen(file.c_str(), "w", stdout);
    // print output
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    const int iterations = 1000;
    const int print_frequency = 100;
    double t = 50, mpl = pow((1e-5) / t, (double) 1 / iterations);
    for (int i = 0; i < iterations; ++i) {
        t *= mpl;
        if (i % (iterations / print_frequency) == 0)
            print_ans(to_string(i / (iterations / print_frequency)));
    }
    return 0;
}