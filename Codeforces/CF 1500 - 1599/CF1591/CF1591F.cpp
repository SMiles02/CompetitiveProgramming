// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+7, MOD = 998244353;
int seg[N*4][6];
vector<int> v;
vector<array<int,2>> w;

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

void build(int i, int l, int r)
{
    seg[i][3]=w[l][0];
    seg[i][4]=w[r][1];
    seg[i][5]=add(sub(seg[i][4],seg[i][3]),1);
    if (l==r)
        return;
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
}

void passDown(int i)
{
    seg[i*2+1][1]=mul(seg[i*2+1][1],seg[i][1]);
    seg[i*2+2][1]=mul(seg[i*2+2][1],seg[i][1]);
    seg[i*2+1][2]=mul(seg[i*2+1][1],seg[i][1]);
    seg[i*2+2][2]=mul(seg[i*2+2][1],seg[i][1]);
    seg[i*2+1][2]=add(seg[i*2+1][2],seg[i][2]);
    seg[i*2+2][2]=add(seg[i*2+2][2],seg[i][2]);
    seg[i][1]=1;
    seg[i][2]=0;
}

int calc(int i)
{
    // cerr<<i<<": "<<seg[i][2]<<" "<<seg[i][4]-seg[i][3]+1<<"\n";
    return add(mul(seg[i][0],seg[i][1]),mul(seg[i][2],seg[i][5]));
}

void recalc(int i)
{
    seg[i][0]=add(calc(i*2+1),calc(i*2+2));
}

void print(int i, int l, int r)
{
    cout<<i<<" "<<l<<" "<<r<<":\n";
    for (int j=0;j<3;++j)
        cout<<seg[i][j]<<" ";
    cout<<"\n";
}

void op(int i, int cL, int cR, int qL, int qR, int op1, int op2)
{
    if (cR<qL||qR<cL)
        return;
    if (qL<=cL&&cR<=qR)
    {
        seg[i][1]=mul(seg[i][1],op1);
        seg[i][2]=mul(seg[i][2],op1);
        seg[i][2]=add(seg[i][2],op2);
        if (i==0&&op1==MOD-1)
        {
            print(i,cL,cR);
        }
        // print(i,cL,cR);
        return;
    }
    passDown(i);
    op(i*2+1,cL,cL+(cR-cL)/2,qL,qR,op1,op2);
    op(i*2+2,cL+(cR-cL)/2+1,cR,qL,qR,op1,op2);
    recalc(i);
    // print(i,cL,cR);
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,l=1,r,mid,sm;
    cin>>n;
    int a[n];
    set<int> s;
    s.insert(1e9+1);
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i : s)
        v.push_back(i);
    for (int i : v)
    {
        w.push_back({l,i});
        // cerr<<l<<" "<<i<<"\n";
        l=i+1;
    }
    m=sz(v);
    l=0;
    r=m-1;
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (a[0]>w[mid][1])
            l=mid+1;
        else
            r=mid;
    }
    build(0,0,m-1);
    op(0,0,m-1,0,l,0,1);
    for (int i=1;i<n;++i)
    {
        l=0;
        r=m-1;
        while (l<r)
        {
            mid=l+(r-l)/2;
            if (a[i]>w[mid][1])
                l=mid+1;
            else
                r=mid;
        }
        sm=calc(0);
        cout<<"Operations:\n";
        op(0,0,m-1,0,m-1,MOD-1,sm);
        op(0,0,m-1,l+1,m-1,0,0);
        print(0,0,1);print(1,0,0);print(2,1,1);
        return 0;
    }
    cout<<calc(0)<<"\n";
    return 0;
}