#include <bits/stdc++.h>
using namespace std;

struct trie {
    int c;
    vector<array<int, 26>> node;
    vector<int> cnt;
    trie(int max_nodes) : c(0), node(max_nodes + 3), cnt(max_nodes + 3) {}
    void add(string& s) {
        int cur = 0;
        ++cnt[0];
        for (auto i : s) {
            if (!node[cur][i - 'a']) {
                node[cur][i - 'a'] = ++c;
            }
            cur = node[cur][i - 'a'];
            ++cnt[cur];
        }
    }
    long long check(string& s) {
        int cur = 0;
        long long ans = 0;
        for (auto i : s) {
            if (!node[cur][i - 'a']) {
                return ans;
            }
            cur = node[cur][i - 'a'];
            ans += cnt[cur];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, tot = 0;
    cin >> n;
    long long ans;
    vector<string> s(n);
    trie t(1e6);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        t.add(s[i]);
        tot += s[i].size();
    }
    ans = 2LL * tot * n;
    for (int i = 0; i < n; ++i) {
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        ans -= t.check(tmp) * 2;
    }
    cout << ans;
    return 0;
}