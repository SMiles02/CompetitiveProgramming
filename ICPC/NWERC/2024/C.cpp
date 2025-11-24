#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int> x, vector<int> y, int p, int q) {
    for (int& i : x) {
        i *= p;
    }
    for (int& i : y) {
        i *= q;
    }
    vector<array<int, 2>> v(5);
    for (int i = 0; i < 5; ++i) {
        v[i] = {x[i], y[i]};
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}