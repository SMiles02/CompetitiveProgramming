struct coordinate_compression {
    vector<array<int, 2>> compress;
    coordinate_compression(vector<int> v) {
        sort(v.begin(), v.end());
        int cnt = 0;
        for (auto i : v) {
            if (compress.empty() || i != compress.back()[0]) {
                compress.push_back({i, cnt++});
            }
        }
    }
    int get_compress(int x) {
        int l = 0, r = compress.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (compress[m][0] < x) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return compress[l][1];
    }
};