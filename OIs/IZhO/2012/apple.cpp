// lol i've solved this before but tried to re-do it with a template i made
// but the math(s) ain't math(s)in

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

template<class S, S (*op)(S, S), S (*e)()> struct implicit_segtree {
    // range [0, n]
    struct node {
        S val;
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
            cur_node.val = S;
            return;
        }
        update(cur_node->l, curl, curl + (curr - curl) / 2, i, x);
        update(cur_node->r, curl + (curr - curl) / 2 + 1, curr, i, x);
    }
    void update(int i, S x) {
        update(root, 0, n, i, x);
    }
    S query(node* cur_node, int curl, int curr, int quel, int quer) {
        if (quer < curl || curr < curl || !cur_node)
            return e();
        if (quel <= curl && curr <= quer)
            return cur_node->val;
        return merge(query(cur_node->l, curl, curl + (curr - curl) / 2, quel, quer), query(cur_node->r, curl + (curr - curl) / 2 + 1, curr, quel, quer));
    }
    S query(int l, int r) {
        return query(root, 0, n, l, r);
    }
};

struct S {
    bool all_set;
    int len, sm;
    S() {
        all_set = false;
        len = 0;
        sm = 0;
    }
};

// basic operation
S op(S &a, S &b) {
    if (a.all_set) a.sm = a.len;
    if (b.all_set) b.sm = b.len;
    return {a.all_set && b.all_set, a.len + b.len, a.sm + b.sm};
}

// op(anything, e()) = anything
S e() {
    return {false, 0, 0};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    return 0;
}