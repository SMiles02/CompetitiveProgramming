#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<char> pieces = {'p', 'n', 'b', 'r', 'q', 'k'};
int n, m;
int g[N][N];
vector<pair<int,int>> positions;

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

// Directions for rook, bishop, king, knight
int dxR[] = {-1, 1, 0, 0};
int dyR[] = {0, 0, -1, 1};
int dxB[] = {-1, -1, 1, 1};
int dyB[] = {-1, 1, -1, 1};
int dxK[] = {-1,-1,-1,0,0,1,1,1};
int dyK[] = {-1,0,1,-1,1,-1,0,1};
int dxN[] = {-2,-2,-1,-1,1,1,2,2};
int dyN[] = {-1,1,-2,2,-2,2,-1,1};

int count_attacks(vector<vector<char>>& board, int x, int y) {
    char c = board[x][y];
    bool white = isupper(c);
    c = tolower(c);
    int cnt = 0;

    auto attack = [&](int nx, int ny) {
        if (!ok(nx, ny)) return;
        if (board[nx][ny] == '.') cnt++;
        else if ((isupper(board[nx][ny]) && !white) || (islower(board[nx][ny]) && white)) cnt++;
    };

    if (c == 'p') {
        int dir = white ? -1 : 1;
        for (int dy : {-1, 1}) {
            int nx = x + dir, ny = y + dy;
            if (ok(nx, ny)) attack(nx, ny);
        }
    } else if (c == 'n') {
        for (int i = 0; i < 8; i++) {
            int nx = x + dxN[i], ny = y + dyN[i];
            if (ok(nx, ny)) attack(nx, ny);
        }
    } else if (c == 'k') {
        for (int i = 0; i < 8; i++) {
            int nx = x + dxK[i], ny = y + dyK[i];
            if (ok(nx, ny)) attack(nx, ny);
        }
    } else if (c == 'r' || c == 'q') {
        for (int d = 0; d < 4; d++) {
            for (int step = 1; ; step++) {
                int nx = x + dxR[d]*step, ny = y + dyR[d]*step;
                if (!ok(nx, ny)) break;
                if (board[nx][ny] != '.') {
                    attack(nx, ny);
                    break;
                }
                cnt++;
            }
        }
    }
    if (c == 'b' || c == 'q') {
        for (int d = 0; d < 4; d++) {
            for (int step = 1; ; step++) {
                int nx = x + dxB[d]*step, ny = y + dyB[d]*step;
                if (!ok(nx, ny)) break;
                if (board[nx][ny] != '.') {
                    attack(nx, ny);
                    break;
                }
                cnt++;
            }
        }
    }

    return cnt;
}

bool backtrack(int i, vector<vector<char>>& board) {
    if (i == (int)positions.size()) {
        for (int k = 0; k < (int)positions.size(); k++) {
            auto [x, y] = positions[k];
            int want = g[x][y];
            int got = count_attacks(board, x, y);
            if (got != want) return false;
        }
        cout << "Solution:\n";
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) cout << board[a][b] << " ";
            cout << "\n";
        }
        return true;
    }

    auto [x, y] = positions[i];
    for (char p : pieces) {
        for (char c : {p, (char)toupper(p)}) {
            board[x][y] = c;
            if (backtrack(i + 1, board)) return true;
            board[x][y] = '.';
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] != -1)
                positions.push_back({i, j});
        }

    vector<vector<char>> board(n, vector<char>(m, '.'));
    backtrack(0, board);
}
