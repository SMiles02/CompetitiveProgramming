vector<array<int, 2>> compress(vector<int> v) {
    int cnt = 0;
    vector<array<int, 2>> m;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0 || v[i] != v[i - 1]) {
            m.push_back({v[i], cnt++});
        }
    }
    return m;
}

int get_compress(int x, vector<array<int, 2>>& v) {
    int l = 0, r = v.size() - 1, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (v[m][0] < x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return v[l][1];
}