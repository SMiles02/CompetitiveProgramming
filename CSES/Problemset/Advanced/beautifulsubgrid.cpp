#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
bitset<N> both[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
            if (s[j] == '1')
                for (int k = j + 1; k < n; ++k)
                    if (s[k] == '1')
                        both[i][j][k] = 1;
    }
    return 0;
}