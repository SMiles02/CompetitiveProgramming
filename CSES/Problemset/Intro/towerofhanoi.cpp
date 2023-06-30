#include <bits/stdc++.h>
using namespace std;

void move_top_to(int from, int to, int cnt) {
    if (cnt == 0)
        return;
    move_top_to(from, 6 - from - to, cnt - 1);
    cout << from << " " << to << "\n";
    move_top_to(6 - from - to, to, cnt - 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    move_top_to(1, 3, n);
    return 0;
}