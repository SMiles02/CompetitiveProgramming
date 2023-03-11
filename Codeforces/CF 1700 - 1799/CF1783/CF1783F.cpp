#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3003;
int a[N], b[N];
vector<int> ans;

void do_swap(int x) {
    swap(a[x], a[a[x]]);
    swap(b[x], b[b[x]]);
    ans.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int _ = 0; _ < n * 2; ++_) {
        bool found = false;
        for (int i = 1; i <= n && !found; ++i)
            if (a[i] == b[i] && a[i] != i) {
                do_swap(i);
                found = true;
            }
        if (found)
            continue;
        for (int i = 1; i <= n && !found; ++i)
            if (a[i] != i && b[i] != i) {
                do_swap(i);
                found = true;
            }
        if (found)
            continue;
        for (int i = 1; i <= n && !found; ++i)
            if (a[i] != i || b[i] != i) {
                do_swap(i);
                found = true;
            }
    }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}