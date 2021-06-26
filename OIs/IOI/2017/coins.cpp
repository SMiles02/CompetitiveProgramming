#include <bits/stdc++.h>

std::vector<int> coin_flips(std::vector<int> b, int c) {
    std::vector<int> flips(1);
    int k = 0;
    for (int i=0;i<64;++i)
        k^=(i*b[i]);
    flips[0]=k^c;
    return flips;
}

int find_coin(std::vector<int> b) {
    int k = 0;
    for (int i=0;i<64;++i)
        k^=(i*b[i]);
    return k;
}