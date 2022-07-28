#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int N = 1100, Q = 675;
bool local = false;
int n, cur_score, q_made = 0, last_query_result;
bitset<N> known, ans, cur, answer;
vector<array<int, 2>> e[N][2];

void make_query() {
    if (++q_made > Q) {
        int k = 2;
        while (true)
            ++k;
    }
    for (int i = 1; i <= n; ++i) {
        if (cur[i])
            cout << "T";
        else
            cout << "F";
    }
    cout << endl;
    if (local) {
        cur_score = 0;
        for (int i = 1; i <= n; ++i)
            cur_score += answer[i] == cur[i];
        cout << cur_score << endl;
    }
    else
        cin >> cur_score;
    last_query_result = cur_score;
}

void dfs(int c, int x) {
    // cout << "We know that " << c << " is " << x << endl;
    known[c] = 1;
    ans[c] = x;
    if (cur[c] != x) {
        ++cur_score;
        // cout << "Increased score." << endl;
        cur[c] = x;
    }
    for (auto i : e[c][x])
        if (!known[i[0]])
            dfs(i[0], i[1]);
}

void add_edge(int a, int b, int c, int d) {
    e[a][b].push_back({c, d});
    e[c][d].push_back({a, b});
}

int main() {
    cin >> n;
    if (local) {
        string ans_s;
        cin >> ans_s;
        for (int i = 1; i <= n; ++i)
            answer[i] = (ans_s[i - 1] - '0');
    }
    for (int i = 1; i <= n; ++i)
        cur[i] = get_rand(0, 1);
    make_query();
    vector<int> v, w;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    int tmp, x, y;
    while (cur_score < n) {
        w.clear();
        for (int i = 0; i < v.size() && cur_score < n; i += 2) {
            tmp = cur_score;
            if (i + 1 == v.size()) {
                x = v[i];
                cur[x] = 1 - cur[x];
                make_query();
                if (tmp + 1 == cur_score)
                    dfs(x, cur[x]);
                else
                    dfs(x, 1 - cur[x]);
            }
            else {
                x = v[i];
                y = v[i + 1];
                cur[x] = 1 - cur[x];
                cur[y] = 1 - cur[y];
                make_query();
                if (tmp == cur_score) {
                    add_edge(x, cur[x], y, 1 - cur[y]);
                    add_edge(x, 1 - cur[x], y, cur[y]);
                    w.push_back(x);
                }
                else if (tmp == cur_score + 2) {
                    dfs(x, 1 - cur[x]);
                    dfs(y, 1 - cur[y]);
                }
                else {
                    dfs(x, cur[x]);
                    dfs(y, cur[y]);
                }
            }
        }
        // cout << "Looped, " << cur_score << endl;
        swap(v, w);
    }
    if (last_query_result != n)
        make_query();
    return 0;
}

// att 10