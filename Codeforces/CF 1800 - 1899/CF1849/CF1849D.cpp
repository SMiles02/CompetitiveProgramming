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

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> s(3);
    vector<bool> done(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    while (!s[2].empty()) {
        ++ans;
        int l, r;
        l = r = *s[2].begin();
        s[2].erase(l);
        done[l] = true;
        while (0 <= l - 1 && !done[l - 1] && a[l] != 0) {
            --l;
            s[a[l]].erase(l);
            done[l] = true;
        }
        while (r + 1 < n && !done[r + 1] && a[r] != 0) {
            ++r;
            s[a[r]].erase(r);
            done[r] = true;
        }
    }
    vector<array<int, 2>> v = {{-1, -1}};
    for (int i = 0; i <= n; ++i) {
        if (i == n || done[i]) {
            if (v.size() == 1) {
                continue;
            }
            if (v[1][0] == 0) {
                for (int j = 1; j < v.size(); ++j) {
                    if (v[j][0] == 0) {
                        ans += v[j][1] - 1;
                    }
                    else {
                        ++ans;
                    }
                }
                if (v.back()[0] == 0) {
                    ++ans;
                }
            }
            else {
                bool test = false;
                for (int j = 1; j < v.size(); ++j) {
                    if (v[j][0] == 0) {
                        ans += v[j][1] - 1;
                        test |= v[j][1] > 1;
                    }
                    else {
                        ++ans;
                    }
                }
                if (test && v.back()[0] == 1) {
                    --ans;
                }
            }
            while (v.size() > 1) {
                v.pop_back();
            } 
        }
        else {
            if (a[i] != v.back()[0]) {
                v.push_back({a[i], 1});
            }
            else {
                ++v.back()[1];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}