#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll f(int n)
{
    return (n*(n+1))/2;
}

const int N = 4, I = 2, M = 50;

bool ok(int x, int y, int z) {
    ll s1;
    for (int i=-M;i<=M;++i)
        for (int j=-M;j<=M;++j)
            for (int k=-M;k<=M;++k)
                if (i*x+f(x-1)+j*y+f(y-1)+k*z+f(z-1)==0)
                    return 1;
    return 0;
}

int a[8][8][2];
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<=N;i+=I)
        for (int j=i;j<=N;j+=I)
            for (int k=j;k<=N;k+=I)
                if (!ok(i,j,k))
                    cout<<i<<" "<<j<<" "<<k<<"\n";
    // for (int i=0;i<8;++i)
    //     for (int j=0;j<8;++j)
    //         cout<<i<<","<<j<<": "<<a[i][j][0]<<" "<<a[i][j][1]<<"\n";
    return 0;
}