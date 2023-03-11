#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5005, INF = 2e9;
int n, m, s, v[N][N], occupied[N][N];
ll score, new_score;
vector<int> snake_lengths;
vector<array<int, 2>> wormholes;
deque<array<int, 4>> snake_positions[N];
array<int, 4> last_change;
bitset<N> is_wormhole[N];
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

double rnd() {
    return double(rng() % INF) / INF;
}

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int new_x(int x) {
    if (x < 0)
        return x + n;
    if (x >= n)
        return x - n;
    return x;
}

int new_y(int y) {
    if (y < 0)
        return y + m;
    if (y >= m)
        return y - m;
    return y;
}

void build_first_stupid() {
    // just stupidly put snakes on the first row LtR, then second row RtL, and so on...
    // make it less bad later
    int cur_snake = 0, len_done = 0, j, d, trg;
    for (int i = 0; i < n && cur_snake < s; ++i) {
        if (i & 1) {
            j = m - 1;
            trg = -1;
            d = -1;
        }
        else {
            j = 0;
            trg = m;
            d = 1;
        }
        while (j != trg) {
            // cerr << cur_snake << ", " << len_done + 1 << ": " << i << " " << j << endl;
            if (is_wormhole[i][j])
                snake_positions[cur_snake].push_back({i, j, i, j});
            else
                snake_positions[cur_snake].push_back({i, j, -1, -1});
            --occupied[i][j];
            score += v[i][j];
            if (++len_done == snake_lengths[cur_snake]) {
                len_done = 0;
                if (++cur_snake == s)
                    break;
            }
            j += d;
        }
    }
}

void print_raw() {
    for (int i = 0; i < s; ++i) {
        for (auto j : snake_positions[i])
            cout << j[0] << " " << j[1] << " ";
        cout << "\n";
    }
}

void print_ans(string file_name) {
    cerr << "Score in " << file_name << ": " << score << endl;
    // string file = "out/file_" + file_name + ".out";
    // freopen(file.c_str(), "w", stdout);
    // print output
    for (int i = 0; i < s; ++i) {
        cout << snake_positions[i][0][1] << " " << snake_positions[i][0][0];
        bool cur_at_wormhole = false;
        for (int j = 1; j < snake_lengths[i]; ++j) {
            int dir_change = -1, old_x, old_y;
            if (snake_positions[i][j - 1][2] != -1) {
                old_x = snake_positions[i][j - 1][2];
                old_y = snake_positions[i][j - 1][3];
            }
            else {
                old_x = snake_positions[i][j - 1][0];
                old_y = snake_positions[i][j - 1][1];
            }
            for (int k = 0; k < 4; ++k)
                if (new_x(old_x + dx[k]) == snake_positions[i][j][0] && new_y(old_y + dy[k]) == snake_positions[i][j][1])
                    dir_change = k;
            assert(dir_change != -1);
            if (dir_change == 0)
                cout << " L";
            else if (dir_change == 1)
                cout << " R";
            else if (dir_change == 2)
                cout << " U";
            else
                cout << " D";
            if (snake_positions[i][j - 1][2] != -1)
                cout << " " << snake_positions[i][j][2] << " " << snake_positions[i][j][3];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> s;
    snake_lengths.resize(s);
    for (int i = 0; i < s; ++i)
        cin >> snake_lengths[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            string tmp;
            cin >> tmp;
            if (tmp == "*") {
                v[i][j] = 0;
                is_wormhole[i][j] = 1;
                wormholes.push_back({i, j});
                occupied[i][j] = 4;
            }
            else {
                v[i][j] = stoi(tmp);
                occupied[i][j] = 1;
            }
        }
    build_first_stupid();
    // print_raw();
    print_ans("0");
    // return 0;
    // const int iterations = 1000;
    // const int print_frequency = 100;
    // double t = 50, mpl = pow((1e-5) / t, (double) 1 / iterations);
    // for (int i = 0; i < iterations; ++i) {
    //     t *= mpl;
    //     int x = get_rand(0, s - 1), newx, newy;
    //     new_score = score;
    //     bool change_made = false;
    //     vector<int> dd(4);
    //     shuffle(dd.begin(), dd.end(), rng);
    //     for (auto j : dd) {
    //         newx = new_x(snake_positions[x][0] + dx[j]);
    //         newy = new_y(snake_positions[x][1] + dy[j]);
    //         if (occupied[newx][newy] > 0) {

    //         }
    //     }
    //     // annealing options
    //     if (new_score >= score || rnd() < exp((new_score - score) / t))
    //         score = new_score;
    //     else if (change_made) {
    //         s[x].pop_front();
    //         s[x].push_back(last_change);
    //     }
    //     if (i % (iterations / print_frequency) == 0)
    //         print_ans(to_string(i / (iterations / print_frequency)));
    // }
    return 0;
}