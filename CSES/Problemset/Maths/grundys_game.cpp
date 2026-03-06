#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> grundy_number(N);
    for (int i = 1; i < N; ++i) {
        vector<bool> mex(i + 3);
        for (int j = 1; j * 2 < i; ++j) {
            mex[min(i + 2, grundy_number[j] ^ grundy_number[i - j])] = true;
        }
        for (int j = 0; j < i + 3; ++j) {
            if (!mex[j]) {
                grundy_number[i] = j;
                break;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n >= N || grundy_number[n] != 0) cout << "first\n";
        else cout << "second\n";
    }
    return 0;
}