#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 18) + 1;
bitset<N> b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cur = 0;
    long long x;
    cin >> n >> x;
    if (x < N)
        b[x] = 1;
    vector<int> ans;
    for (int i = 1; i < (1 << n); ++i)
        if (!b[i]) {
            ans.push_back(cur ^ i);
            cur = i;
            if ((x ^ i) < N)
                b[x ^ i] = 1;
        }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}