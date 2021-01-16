#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll C;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

struct Vertex {
    int l, r;
    ll sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        l = lb;
        r = rb;
    }

    void extend() {
        if (left_child)
            return;
        if (l<r) {
            int t =  l+(r-l)/2;
            left_child = new Vertex(l, t);
            right_child = new Vertex(t+1, r);
        }
    }

    void add(int L, int R, int x) {
        if (L<=l&&r<=R)
        {
            if (sum<C)
                sum += x;
            return;
        }
        if (R<l||r<L)
            return;
        extend();
        left_child->add(L, R, x);
        right_child->add(L, R, x);
    }

    ll get_sum(ll x) {
        sum+=x;
        if (left_child)
            return left_child->get_sum(sum) + right_child->get_sum(sum);
        else
            return min(sum,C)*(r-l+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,c;
    cin>>n>>C;
    Vertex* segtree = new Vertex(1,1e9);
    while (n--)
    {
        cin>>a>>b>>c;
        segtree->add(a,b,c);
    }
    cout<<segtree->get_sum(0);
    return 0;
}