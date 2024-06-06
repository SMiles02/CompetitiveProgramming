#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print_bits(ll n) {
    for (int i = 61; i >= 0; --i) {
        cout << ((n & (1LL << i)) > 0);
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a = 481885160128643072, b = 45035996273704960;
    print_bits(a);
    print_bits(b);
    return 0;
}