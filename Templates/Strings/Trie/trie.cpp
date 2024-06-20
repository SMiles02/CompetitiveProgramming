struct trie {
    int c;
    vector<array<int, 26>> node;
    vector<int> cnt;
    trie(int max_nodes) : c(0), node(max_nodes + 3), cnt(max_nodes + 3) {}
    void add(string& s) {
        int cur = 0;
        ++cnt[0];
        for (auto i : s) {
            if (!node[cur][i - 'a']) {
                node[cur][i - 'a'] = ++c;
            }
            cur = node[cur][i - 'a'];
            ++cnt[cur];
        }
    }
    long long check(string& s) {
        // do whatever you want in here
        // currently it checks the length of the common prefix it has with all elements of the trie
        int cur = 0;
        long long ans = 0;
        for (auto i : s) {
            if (!node[cur][i - 'a']) {
                return ans;
            }
            cur = node[cur][i - 'a'];
            ans += cnt[cur];
        }
        return ans;
    }
};