#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int INF = 1e9, X = 2 * INF;
double t=50; //starting temperature
 
double rnd() {
    return double(rng() % X) / X;
}

const int N = 105, M = N * N;
int n, m, a[N][2], x[M][2];
bitset<M> pos;
multiset<int, greater<int>> s[N];

int check_score(int i) {
    return max(*s[i].begin() - a[i][0], 0);
}

int swap_score(array<int, 4>& p) {
    int tmp = check_score(p[0]) + check_score(p[1]);
    // cerr << "oki" << endl;
    s[p[0]].erase(s[p[0]].lower_bound(p[2]));
    s[p[1]].erase(s[p[1]].lower_bound(p[3]));
    s[p[0]].insert(p[3]);
    s[p[1]].insert(p[2]);
    tmp -= (check_score(p[0]) + check_score(p[1]));
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i][0] >> a[i][1];
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x[i][0] >> x[i][1];
        pos[i] = get_rand(0, 1);
        if (pos[i] == 0) {
            s[x[i][0]].insert(a[x[i][0]][1]);
            s[x[i][1]].insert(a[x[i][1]][1]);
        }
        else {
            s[x[i][0]].insert(a[x[i][1]][1]);
            s[x[i][1]].insert(a[x[i][0]][1]);
        }
        // cout << pos[i];
    }
    // cout << endl;
    int ans, cur = 0, tmp, j;
    for (int i = 1; i <= n; ++i)
        if (!s[i].empty())
            cur += check_score(i);
    ans = cur;
    // cout << cur << endl;
    array<int, 4> p;
    int iterations = 8e6;
    double mpl = pow((1e-5)/t, (double)1/iterations);
    for (int _ = 0; _ < iterations; ++_) {
        t *= mpl;
        j = get_rand(0, m - 1);
        if (pos[j] == 0)
            p = {x[j][0], x[j][1], a[x[j][0]][1], a[x[j][1]][1]};
        else
            p = {x[j][0], x[j][1], a[x[j][1]][1], a[x[j][0]][1]};
        tmp = swap_score(p);
        // cout << j << " !: " << tmp << endl;
        if (tmp >= 0 || rnd() < exp((tmp) / t)) {
            cur -= tmp;
            ans = min(ans, cur);
            pos[j] = 1 - pos[j];
        }
        else {
            swap(p[2], p[3]);
            swap_score(p);
        }
        // for (int i = 0; i < m; ++i)
        //     cout << pos[i];
        // cout << endl << cur << endl;
    }
    cout << ans;
    return 0;
}