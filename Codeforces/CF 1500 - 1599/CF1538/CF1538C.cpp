#include <bits/stdc++.h>
using namespace std;

template<class S, S (*op)(S, S), S (*e)()> struct implicit_segtree {
    // range [0, n]
    struct node {
        S val = e();
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    int n;
    node *root;
    implicit_segtree(int n) : n(n) { root = newnode(); }
    void update(node *&cur_node, int curl, int curr, int i, S x) {
        if (i < curl || curr < i)
            return;
        if (!cur_node) 
            cur_node = newnode();
        if (curl == curr) {
            cur_node->val = x;
            return;
        }
        update(cur_node->l, curl, curl + (curr - curl) / 2, i, x);
        update(cur_node->r, curl + (curr - curl) / 2 + 1, curr, i, x);
        if (!cur_node->l)
            cur_node->val = cur_node->r->val;
        else if (!cur_node->r)
            cur_node->val = cur_node->l->val;
        else
            cur_node->val = op(cur_node->l->val, cur_node->r->val);
    }
    void update(int i, S x) {
        update(root, 0, n, i, x);
    }
    S query(node* cur_node, int curl, int curr, int quel, int quer) {
        if (quer < curl || curr < curl || !cur_node)
            return e();
        if (quel <= curl && curr <= quer)
            return cur_node->val;
        return op(query(cur_node->l, curl, curl + (curr - curl) / 2, quel, quer), query(cur_node->r, curl + (curr - curl) / 2 + 1, curr, quel, quer));
    }
    S query(int l, int r) {
        return query(root, 0, n, l, r);
    }
};

using S = int;

// basic operation
S op(S a, S b) { return a + b; }

// op(anything, e()) = anything
S e() { return 0; }

void solve() {
    int n, l, r;
    long long ans = 0;
    cin >> n >> l >> r;
    implicit_segtree<S, op, e> seg(1e9);
    while (n--) {
        int k;
        cin >> k;
        if (k < r) {
            ans += seg.query(max(1, l - k), r - k);
            seg.update(k, seg.query(k, k) + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}