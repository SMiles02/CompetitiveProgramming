#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= (1 << n); ++i) {
        int max_weak = i - 1, min_weak = i - 1, players = (1 << n);
        bool ok = true;
        for (auto j : s) {
            if (j == '0') {
                swap(min_weak, max_weak);
                min_weak = players - min_weak - 1;
                max_weak = players - max_weak - 1;
            }
            if (max_weak == 0) {
                ok = false;
                break;
            }
            min_weak = max(min_weak - 1, 0);
            --max_weak;
            min_weak = max(min_weak - (players - 2 - min_weak), 0) / 2;
            max_weak /= 2;
            players /= 2;
            if (j == '0') {
                swap(min_weak, max_weak);
                min_weak = players - min_weak - 1;
                max_weak = players - max_weak - 1;
            }
        }
        if (ok)
            cout << i << " ";
    }
    return 0;
}