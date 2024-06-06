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

vector<string> ans[100];

void solve() {
    int n;
    cin >> n;
    for (auto i : ans[n]) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ans[1].push_back("1");
    ans[3].push_back("169");
    ans[3].push_back("196");
    ans[3].push_back("961");
    for (int i = 5; i <= 99; i += 2) {
        for (auto j : ans[i - 2]) {
            ans[i].push_back(j);
            ans[i].back() += "00";
        }
        ans[i].push_back("1");
        for (int j = 0; j < (i - 3) / 2; ++j) {
            ans[i].back() += "0";
        }
        ans[i].back() += "6";
        for (int j = 0; j < (i - 3) / 2; ++j) {
            ans[i].back() += "0";
        }
        ans[i].back() += "9";
        ans[i].push_back("9");
        for (int j = 0; j < (i - 3) / 2; ++j) {
            ans[i].back() += "0";
        }
        ans[i].back() += "6";
        for (int j = 0; j < (i - 3) / 2; ++j) {
            ans[i].back() += "0";
        }
        ans[i].back() += "1";
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}