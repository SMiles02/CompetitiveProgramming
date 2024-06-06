struct trie {
    int l, c;
    vector<array<int, 2>> node;
    trie(int l, int max_members) : l(l), c(0), node((l + 2) * max_members + 3) {}
    void add(int x) {
        int cur = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (!node[cur][has_bit]) {
                node[cur][has_bit] = ++c;
            }
            cur = node[cur][has_bit];
            ++cnt[cur];
        }
    }
    int find_max(int x) {
        int cur = 0, ans = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (node[cur][!has_bit]) {
                ans += 1 << i;
                cur = node[cur][!has_bit];
            }
            else {
                cur = node[cur][has_bit];
            }
        }
        return ans;
    }
    int find_min(int x) {
        int cur = 0, ans = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (node[cur][has_bit]) {
                cur = node[cur][has_bit];
            }
            else {
                ans += 1 << i;
                cur = node[cur][!has_bit];
            }
        }
        return ans;
    }
};