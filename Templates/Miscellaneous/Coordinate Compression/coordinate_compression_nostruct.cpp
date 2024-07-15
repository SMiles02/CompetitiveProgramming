map<int, int> compress(vector<int> v) {
    int cnt = 0;
    map<int, int> m;
    sort(v.begin(), v.end());
    m[v[0]] = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0 || v[i] != v[i - 1]) {
            m[v[i]] = cnt++;
        }
    }
    return m;
}