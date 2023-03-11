#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 15, MX = 7;
vector<int> v;

bool check() {
    int o = 0, e = 0;
    for (int i : v) {
        if (i & 1)
            ++o;
        else
            ++e;
    }
    if (o > 1 && e > 1)
        return true;
    for (int x = 1; x <= N * 20; ++x) {
        bool ok = true;
        for (int i = 0; i < v.size(); ++i)
            for (int j = i + 1; j < v.size(); ++j)
                if (__gcd(v[i] + x, v[j] + x) != 1)
                    ok = false;
        if (ok)
            return true;
    }
    if (e == 0 || o == 0)
        cout << "!!!!!\n";
    return false;
}

void rec(int i, int sz) {
    if (i > N || sz == MX) {
        if (!check()) {
            for (int j : v)
                cout << j << " ";
            cout << endl;
        }
        return;
    }
    rec(i + 1, sz);
    v.push_back(i);
    rec(i + 1, sz + 1);
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rec(1, 0);
    return 0;
}