#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

string a = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int, 2>> cnt(26);
    vector<int> v(26), w;
    for (int i = 0; i < 26; ++i)
        cnt[i][1] = i;
    for (auto i : s)
        ++cnt[i - 'a'][0];
    sort(cnt.rbegin(), cnt.rend());
    array<int, 2> ans = {(int)1e9, 0};
    for (int i = 1; i <= 26; ++i)
        if (n % i == 0) {
            int cur = 0;
            for (int j = 0; j < i; ++j)
                cur += abs((n / i) - cnt[j][0]);
            for (int j = i; j < 26; ++j)
                cur += cnt[j][0];
            ans = min(ans, {cur / 2, i});
        }
    cout << ans[0] << "\n";
    for (int i = 0; i < ans[1]; ++i) {
        while (cnt[i][0] > n / ans[1]) {
            --cnt[i][0];
            ++v[cnt[i][1]];
        }
        while (cnt[i][0] < n / ans[1]) {
            ++cnt[i][0];
            w.push_back(cnt[i][1]);
        }
    }
    for (int i = ans[1]; i < 26; ++i)
        while (cnt[i][0] > 0) {
            --cnt[i][0];
            ++v[cnt[i][1]];
        }
    for (auto i : s) {
        if (v[i - 'a'] > 0) {
            --v[i - 'a'];
            cout << a[w.back()];
            w.pop_back();
        }
        else
            cout << i;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}