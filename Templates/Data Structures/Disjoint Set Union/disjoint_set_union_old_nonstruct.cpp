#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 69;
int p[N], sz[N];
 
int find_set(int i) {
    if (i == p[i]) return i;
    return p[i] = find_set(p[i]);
}
 
void make_set(int n) {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
}
 
void unite(int i, int j) {
    i = find_set(i);
    j = find_set(j);
    if (i != j) {
        if (sz[i] < sz[j])
            swap(i, j);
        p[b] = a;
        sz[a] += sz[b];
    }
}