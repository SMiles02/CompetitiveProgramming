#include <vector>
#include <map>
#include <set>
using namespace std;

long long revenue(int n, int k, vector<long long> a) {
    int neg = 0, pos = 0;
    long long ans = 0, cur = 0;
    map<long long, int> m;
    set<long long> s;
    for (auto i : a) {
        if (i > 0) {
            ++pos;
            ++m[i];
            s.insert(i);
        }
        else if (i < 0) {
            ++neg;
            ++m[i];
            s.insert(-i);
        }
    }
    for (auto i : s) {
        cur += i * (m[i] - m[-i]);
        pos -= m[i];
        neg -= m[-i];
        ans = max(ans, cur + i * (pos - neg) - k * i);
    }
    return ans;
}