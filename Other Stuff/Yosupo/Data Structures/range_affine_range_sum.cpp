// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

template<class T, class U> struct lazy_segtree {
    // range [0,n]

    // merge(ID,x) = x
    const T ID = 0;
    const U D = {1, 0};
    int n;
    vector<T> data;
    vector<U> lazy;
    lazy_segtree(int n) : n(n), data(n * 4 + 4), lazy(n * 4 + 4, D) {}
    
    T merge(T a, T b) {
        // The main operation
        return add(a, b);
    }

    void passDown(int i) {
        // Pushing the lazy values down
        lazy[i * 2 + 1][0] = mul(lazy[i * 2 + 1][0], lazy[i][0]);
        lazy[i * 2 + 1][1] = mul(lazy[i * 2 + 1][1], lazy[i][0]);
        lazy[i * 2 + 1][1] = add(lazy[i * 2 + 1][1], lazy[i][1]);
        lazy[i * 2 + 2][0] = mul(lazy[i * 2 + 2][0], lazy[i][0]);
        lazy[i * 2 + 2][1] = mul(lazy[i * 2 + 2][1], lazy[i][0]);
        lazy[i * 2 + 2][1] = add(lazy[i * 2 + 2][1], lazy[i][1]);
        lazy[i][0] = 1;
        lazy[i][1] = 0;
    }

    T calc(int i, int x) {
        // Value at this node
        return add(mul(data[i], lazy[i][0]), mul(lazy[i][1], x));
    }

    void recalc(int i, int l, int r) {
        data[i] = merge(calc(i * 2 + 1, (r - l) / 2 + 1), calc(i * 2 + 2, r - l - (r - l) / 2));
    }   

    void update(int i, int l, int r, int qL, int qR, U x) {
        if (r < qL || qR < l)
            return;
        if (qL <= l && r <= qR) {
            // Update goes in here
            lazy[i][0] = mul(lazy[i][0], x[0]);
            lazy[i][1] = mul(lazy[i][1], x[0]);
            lazy[i][1] = add(lazy[i][1], x[1]);
            return;
        }
        passDown(i);
        update(i * 2 + 1, l, l + (r - l) / 2, qL, qR, x);
        update(i * 2 + 2, l + (r - l) / 2 + 1, r, qL, qR, x);
        recalc(i, l, r);
    }
    void update(int qL, int qR, U x) { update(0, 0, n, qL, qR, x); }
    
    T query(int i, int l, int r, int qL, int qR) {
        if (r < qL || qR < l)
            return ID;
        if (qL <= l && r <= qR)
            return calc(i, r - l + 1);
        passDown(i);
        T x = merge(query(i * 2 + 1, l, l + (r - l) / 2, qL, qR), query(i * 2 + 2, l + (r - l) / 2 + 1, r, qL, qR));
        recalc(i, l, r);
        return x;
    }
    T query(int l, int r) { return query(0, 0, n, l, r); }
    T query_all() { return calc(0); }

    void clean(int i, int l, int r) {
        cout << i << ": " << data[i] << " " << lazy[i][0] << " " << lazy[i][1] << "\n";
        cout << calc(i) << "\n";
        if (l == r) {
            cerr << i << ": " << data[i] << " " << lazy[i][0] << " " << lazy[i][1] << "\n";
            cerr << calc(i) << "\n";
            return;
        }
        passDown(i);
        clean(i * 2 + 1, l, l + (r - l) / 2);
        clean(i * 2 + 2, l + (r - l) / 2 + 1, r);
        recalc(i);
        cerr << i << ": " << data[i] << " " << lazy[i][0] << " " << lazy[i][1] << "\n";
        cerr << calc(i) << "\n";
    }
    void clean() { clean(0, 0, n); }

    void printAll(int i, int l, int r) {
        cout << i << ": " << data[i] << " " << lazy[i][0] << " " << lazy[i][1] << "\n";
        cout << calc(i) << "\n";
        if (l == r)
            return;
        printAll(i * 2 + 1, l, l + (r - l) / 2);
        printAll(i * 2 + 2, l + (r - l) / 2 + 1, r);
    }
    void printAll() { printAll(0, 0, n); }
};
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, k, t, l, r, b, c;
    cin>>n>>q;
    lazy_segtree<int, array<int, 2>> seg(n);
    for (int i=0;i<n;++i)
    {
        cin>>k;
        seg.update(i,i,{0,k});
    }
    while (q--) {
        cin>>t>>l>>r;
        // seg.clean();
        if (t==0) {
            cin>>b>>c;
            seg.update(l,r-1,{b,c});
        }
        else {
            // if (q == 0) {
            //     seg.printAll(); 
            //     cout << "\n";
            //     seg.clean();
            // }
            cout<<seg.query(l,r-1)<<"\n";
        }
    }
    return 0;
}