#include <bits/stdc++.h>
using namespace std;

int cnt;
set<int> s;
set<int, greater<int>> t;
multiset<int> gaps;

void print_ans() {
    if (cnt < 3)
        cout << "0\n";
    else
        cout << *t.begin() - *s.begin() - *(--gaps.end()) << "\n";
}

void add_pile(int x) {
    if (cnt) {
        if (s.upper_bound(x) == s.end())
            gaps.insert(x - *t.begin());
        else if (t.upper_bound(x) == t.end())
            gaps.insert(*s.begin() - x);
        else {
            gaps.erase(gaps.find(*s.upper_bound(x) - *t.upper_bound(x)));
            gaps.insert(*s.upper_bound(x) - x);
            gaps.insert(x - *t.upper_bound(x));
        }
    }
    s.insert(x);
    t.insert(x);
    ++cnt;
}

void remove_pile(int x) {
    if (cnt < 3)
        gaps.clear();
    else if (s.upper_bound(x) == s.end())
        gaps.erase(gaps.find(x - *t.upper_bound(x)));
    else if (t.upper_bound(x) == t.end())
        gaps.erase(gaps.find(*s.upper_bound(x) - x));
    else {
        gaps.erase(gaps.find(x - *t.upper_bound(x)));
        gaps.erase(gaps.find(*s.upper_bound(x) - x));
        gaps.insert(*s.upper_bound(x) - *t.upper_bound(x));
    }
    s.erase(x);
    t.erase(x);
    --cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, k, x;
    cin >> n >> q;
    while (n--) {
        cin >> x;
        add_pile(x);
    }
    print_ans();
    while (q--) {
        cin >> k >> x;
        if (k == 1)
            add_pile(x);
        else
            remove_pile(x);
        print_ans();
    }
    return 0;
}