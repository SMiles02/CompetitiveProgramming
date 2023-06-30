#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2023;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<bool> b(N + 1);
    b[2] = b[3] = b[6] = true;
    while (true) {
        bool change_found = false;
        for (int i = 2; i <= N; ++i)
            for (int k = i + 2; k <= N; ++k)
        if (!change_found)
            break;
    }
    vector<int> v;
    for (int i = 2; i <= N; ++i)
        if (b[i])
            v.push_back(i);
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0)
            cout << ",";
        cout << v[i];
    }
    return 0;
}