#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n;
    cin >> n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i < 16; ++i) {
        for (int j = 1; j < i; ++j) {
            if ((i ^ j) < i) {
                cout << i << " " << j << "\n";
            }
        }
    }
    return 0;
}