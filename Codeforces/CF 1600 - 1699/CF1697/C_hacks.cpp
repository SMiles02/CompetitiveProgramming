#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int main() {
    string s = string(N / 2, 'a') + string(N / 2, 'b');
    string t = string(N / 2, 'b') + string(N / 2, 'a');
    cout << 1 << endl << N << endl << s << endl << t << endl;
    return 0;
}