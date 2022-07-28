#include <bits/stdc++.h>
using namespace std;

const int N = 24 * 60;

bool is_palindrome(int x) {
    int h = x / 60, m = x % 60;
    return (h / 10 == m % 10 && h % 10 == m / 10);
}

void solve() {
    string s;
    cin >> s;
    int x, t = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    cin >> x;
    set<int> ans;
    for (int i = 0; i < N; ++i)
        if (is_palindrome((t + x * i) % N))
            ans.insert((t + x * i) % N);
    cout << ans.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}