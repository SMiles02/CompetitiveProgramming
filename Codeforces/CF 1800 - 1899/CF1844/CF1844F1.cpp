#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int c;

ll get_score(vector<ll>& v) {
    ll score = 0;
    for (int i = 1; i < v.size(); ++i) {
        score += abs(v[i] - v[i - 1] - c);
    }
    return score;
}

void solve() {
    int n;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (c >= 0) {
        sort(a.begin(), a.end());
    }
    else {
        sort(a.rbegin(), a.rend());
        ll min_tot = get_score(a);
        vector<ll> ans;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = (int)a.size() - 1, m;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                vector<ll> cur = ans;
                cur.push_back(a[m]);
                for (int j = 0; j < a.size(); ++j) {
                    if (j != m) {
                        cur.push_back(a[j]);
                    }
                }
                if (get_score(cur) == min_tot) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
            ans.push_back(a[l]);
            vector<ll> b;
            for (int j = 0; j < a.size(); ++j) {
                if (j != l) {
                    b.push_back(a[j]);
                }
            }
            swap(a, b);
        }
        swap(a, ans);
    }
    for (int i : a) {
        cout << i << " ";
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