#include <vector>
using namespace std;

vector<vector<char>> solve(long long K) {
    if (K == 1) {
        return {{'.'}};
    }
    vector<vector<char>> ans(200, vector<char>(200, '#'));
    ans[0][0] = '.';
    ans[199] = vector<char>(200, '.');
    int x = 0;
    long long done = 0;
    for (int p = 0; done != K; ++p) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans[x + i][x + j] = '.';
            }
        }
        ans[x + 1][x + 1] = '#';
        if ((1LL << p) & K) {
            for (int i = x; i < 200; ++i) {
                ans[i][x] = '.';
            }
            done ^= 1LL << p;
        }
        x += 2;
    }
    return ans;
}
