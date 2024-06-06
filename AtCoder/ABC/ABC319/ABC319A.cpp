// starting late

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<string, int> m;
    m["tourist"] = 3858;
    m["ksun48"] = 3679;
    m["Benq"] = 3658;
    m["Um_nik"] = 3648;
    m["apiad"] = 3638;
    m["Stonefeang"] = 3630;
    m["ecnerwala"] = 3613;
    m["mnbvmar"] = 3555;
    m["newbiedmy"] = 3516;
    m["semiexp"] = 3481;
    string s;
    cin >> s;
    cout << m[s];
    return 0;
}