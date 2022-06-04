#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 1000000;
vector<int> v;

void put_in(int x) {
    if (1 <= x && x <= N) {
        v.push_back(x);
        // for (int j = 19; j >= 0; --j)
        //     cout << min(1, (1 << j) & x);
        // cout << "\n";
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 100; ++i) {
        put_in(i);
        put_in(i * 100);
        put_in(i * 10000);
    }
    put_in(1e6);
    cout << sz(v) << "\n";
    for (int i : v)
        cout << i << " ";
    return 0;
}