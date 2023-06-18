#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <variant>
using namespace std;

struct disjoint_set_union {
  vector<int> p, sz;
  vector<vector<int>> unpaired_nodes;
  disjoint_set_union(int n) : p(n), sz(n, 1), unpaired_nodes(n) {
    iota(p.begin(), p.end(), 0);
  }
  int find_set(int i) { return i == p[i] ? i : p[i] = find_set(p[i]); }
  bool is_lead_node(int i) { return i == find_set(i); }
  int get_unpaired_size(int i) { return unpaired_nodes[find_set(i)].size(); }
  void add_unpaired_node(int i) { unpaired_nodes[find_set(i)].push_back(i); }
  void unite(int i, int j) {
    i = find_set(i);
    j = find_set(j);
    if (i != j) {
      if (unpaired_nodes[i].size() < unpaired_nodes[j].size()) {
        swap(i, j);
      }
      p[j] = i;
      sz[i] += sz[j];
      for (int k : unpaired_nodes[j]) {
        unpaired_nodes[i].push_back(k);
      }
    }
  }
};

variant<bool, vector<pair<int, int>>> find_numbering(int n, vector<int> a) {
  vector<vector<int>> has_degree(n);
  long long total_edges = 0;
  for (int i = 0; i < n; ++i) {
    total_edges += a[i];
    has_degree[a[i]].push_back(i);
  }
  if ((total_edges & 1) || total_edges / 2 >= n) {
    return false;
  }
  disjoint_set_union dsu(n);
  vector<pair<int, int>> edges;
  for (int i = n - 1; i > 0; --i) {
    vector<array<int, 2>> v;
    for (int j : has_degree[i]) {
      has_degree[i - 1].push_back(j);
      dsu.add_unpaired_node(j);
    }
    for (int j : has_degree[i]) {
      if (dsu.is_lead_node(j)) {
        v.push_back({dsu.get_unpaired_size(j), j});
      }
    }
    sort(v.rbegin(), v.rend());
    int id = 0, sz = 0;
    for (auto [y, x] : v) {
      if (sz > 0) {
        edges.push_back(
            {dsu.unpaired_nodes[x].back(), dsu.unpaired_nodes[id].back()});
        dsu.unpaired_nodes[x].pop_back();
        dsu.unpaired_nodes[id].pop_back();
        dsu.unite(x, id);
      }
      id = dsu.find_set(x);
      sz = dsu.get_unpaired_size(id);
    }
    if (sz > 0) {
      return false;
    }
  }
  return edges;
}
