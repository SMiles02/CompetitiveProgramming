#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, N, "n");
    inf.readSpace();
    int m = inf.readInt(1, N, "m");
    inf.readEoln();
    int k_sum = 0, k, x;
    
    for (int i = 1; i <= n; i++)
    {
        k = inf.readInt(1, m);
        k_sum += k;
        ensuref(k_sum <= N, "Sum of k is too large");
        set<int> s;
        while (k--) {
            inf.readSpace();
            x = inf.readInt(1, m);
            ensuref(!s.count(x), "Favourite food is repeated");
            s.insert(x);
        }
        inf.readEoln();
    }

    for (int i = 1; i <= m; ++i) {
        x = inf.readInt(0, N);
        if (i == m)
            inf.readEoln();
        else
            inf.readSpace();
    }

    inf.readEof();
}