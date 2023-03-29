// full sol

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, M = 6;
int n, pre[M], pos[N];
string target = "bessie", s;

struct S {
    long long ans;
    array<int, M> at_each_position;
    array<int, M> go_to;
    array<int, M> mul_prev;
};

S seg[N * 4], no_effect;

S single_character(char c, int i) {
    S basic;
    basic.ans = 0;
    for (int j = 0; j < M; ++j) {
        basic.at_each_position[j] = 0;
        if (c == target[j])
            basic.go_to[pre[j]] = j;
        else
            basic.go_to[pre[j]] = pre[j];
        basic.mul_prev[j] = 0;
    }
    basic.at_each_position[0] = (c == target[0]);
    basic.at_each_position[M - 1] = (c != target[0]);
    if (c == target[M - 1])
        basic.mul_prev[M - 2] = n - i;
    return basic;
}

S op(S a, S b) {
    S merge;
    merge.ans = a.ans + b.ans;
    for (int i = 0; i < M; ++i)
        merge.at_each_position[i] = 0;
    for (int i = 0; i < M; ++i) {
        merge.ans += 1LL * a.at_each_position[i] * b.mul_prev[i];
        merge.go_to[i] = b.go_to[a.go_to[i]];
        merge.at_each_position[b.go_to[i]] += a.at_each_position[i];
        merge.at_each_position[i] += b.at_each_position[i];
        merge.mul_prev[i] = a.mul_prev[i] + b.mul_prev[a.go_to[i]];
    }
    return merge;
}

void build(int i, int l, int r) {
    if (l == r) {
        seg[i] = single_character(s[l], l);
        pos[l] = i;
        return;
    }
    build(i * 2 + 1, l, l + (r - l) / 2);
    build(i * 2 + 2, l + (r - l) / 2 + 1, r);
    seg[i] = op(seg[i * 2 + 1], seg[i * 2 + 2]);
}

S query(int i, int l, int r, int qL, int qR) {
    if (r < qL || qR < l)
        return no_effect;
    if (qL <= l && r <= qR)
        return seg[i];
    return op(query(i * 2 + 1, l, l + (r - l) / 2, qL, qR), query(i * 2 + 2, l + (r - l) / 2 + 1, r, qL, qR));
}

void update_pos(int i, char c) {
    s[i] = c;
    seg[pos[i]] = single_character(c, i);
    i = (pos[i] - 1) / 2;
    while (i > 0) {
        seg[i] = op(seg[i * 2 + 1], seg[i * 2 + 2]);
        i = (i - 1) / 2;
    }
    seg[i] = op(seg[i * 2 + 1], seg[i * 2 + 2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i + 1 < M; ++i)
        pre[i + 1] = i;
    pre[0] = M - 1;
    no_effect.ans = 0;
    for (int i = 0; i < M; ++i) {
        no_effect.at_each_position[i] = 0;
        no_effect.go_to[i] = i;
        no_effect.mul_prev[i] = 0;
    }
    build(0, 0, n - 1);
    cout << query(0, 0, n - 1, 0, n - 1).ans << "\n";
    int q;
    cin >> q;
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        --i;
        update_pos(i, c);
        cout << query(0, 0, n - 1, 0, n - 1).ans << "\n";
    }
    return 0;
}