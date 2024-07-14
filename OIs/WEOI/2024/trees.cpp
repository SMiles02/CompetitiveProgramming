#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= MOD) {
    x -= MOD;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += MOD;
  }
  return x;
}

int mul(int a, int b) {
  return (1LL * a * b) % MOD;
}

void dfs(int cur, int par, vector<vector<int>>& e, vector<int>& ways, vector<int>& ways_constrained) {
  ways[cur] = 1;
  int cnt1 = 0, cnt2 = 1;
  for (int child : e[cur]) {
    if (child == par) {
      continue;
    }
    dfs(child, cur, e, ways, ways_constrained);
    // fill root and one child subtree
    ways[cur] = add(ways[cur], ways_constrained[child]);
    // do not fill root, fill at least two child subtrees
    cnt2 = mul(cnt2, add(ways_constrained[child], 1));
    ways[cur] = sub(ways[cur], ways_constrained[child]);
    // do not fill root, fill only one child subtree
    cnt1 = add(cnt1, ways[child]);
  }
  ways[cur] = add(sub(ways[cur], 1), add(cnt1, cnt2));
  ways_constrained[cur] = 1;
  int cnt = 1;
  for (int child : e[cur]) {
    if (child == par) {
      continue;
    }
    cnt = mul(cnt, add(ways_constrained[child], 1));
  }
  ways_constrained[cur] = add(ways_constrained[cur], sub(cnt, 1));
}

int count_sets(int N, vector<int> u, vector<int> v) {
  vector<vector<int>> e(N);
  vector<int> ways(N), ways_constrained(N);
  for (int i = 0; i + 1 < N; ++i) {
    e[u[i]].push_back(v[i]);
    e[v[i]].push_back(u[i]);
  }
  dfs(0, -1, e, ways, ways_constrained);
  return ways[0];
}
