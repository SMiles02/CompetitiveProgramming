#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 2e5+1;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

int sub(int a, int b) { return add(a,MOD-b); }
 
const int mn = 2e5+1, dv2 = (MOD + 1) / 2;
int seg[mn<<2],lazy[mn<<2][2],rg[mn<<2],ans;
 
int f(int x, int y, int z) // start, diff, length
{
    return add(mul(x, z), mul(mul(mul(z, z - 1), dv2), y));
}
 
void passDown(int i)
{
    lazy[2*i+1][0] = add(lazy[2*i+1][0], lazy[i][0]);
    lazy[2*i+1][1] = add(lazy[2*i+1][1], lazy[i][1]);
    lazy[2*i+2][0] = add(lazy[2*i+2][0], add(lazy[i][0], mul(lazy[i][1], rg[i*2+1])));
    lazy[2*i+2][1] = add(lazy[2*i+2][1], lazy[i][1]);
    lazy[i][0] = 0;
    lazy[i][1] = 0;
}
 
int val(int i)
{
    return add(seg[i], f(lazy[i][0], lazy[i][1], rg[i]));
}
 
void recalc(int i)
{
    seg[i] = add(val(i*2+1), val(i*2+2));
}

void build(int i, int l, int r)
{
    rg[i]=r-l+1;
    if (l==r)
        return;
    build(i*2+1,l,(l+r)>>1);
    build(i*2+2,(l+r+2)>>1,r);
}
 
void update(int i, int cL, int cR, int l, int r, int x, int y)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        lazy[i][0] = add(lazy[i][0], mul(x, cL - l + 1));
        lazy[i][1] = add(lazy[i][1], y);
        return;
    }
    passDown(i);
    update(i*2+1,cL,(cL+cR)>>1,l,r,x,y);
    update(i*2+2,(cL+cR+2)>>1,cR,l,r,x,y);
    recalc(i);
}
 
void query(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        ans=add(ans, val(i));
        return;
    }
    passDown(i);
    query(i*2+1,cL,(cL+cR)>>1,l,r);
    query(i*2+2,(cL+cR+2)>>1,cR,l,r);
    recalc(i);
}

void print(int i, int l, int r) {
    cout << i << " " << l << " " << r << ": " << val(i) << "\n";
    if (l == r)
        return;
    print(i*2+1, l, (l + r) >> 1);
    print(i*2+2, (l + r + 2) >> 1, r);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k,l,r;
    cin >> n >> q;
    vector<int> v(n + 1);
    build(0, 1, n);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        update(0, 1, n, i, n, v[i], v[i]);
    }
    // print(0, 1, n);
    // return 0;
    while (q--)
    {
        cin >> k >> l;
        if (k == 1) {
            cin >> r;
            update(0, 1, n, l, n, sub(r, v[l]), sub(r, v[l]));
            v[l] = r;
        }
        else
        {
            ans = 0;
            query(0, 1, n, 1, l);
            cout << ans << "\n";
        }
    }
    return 0;
}