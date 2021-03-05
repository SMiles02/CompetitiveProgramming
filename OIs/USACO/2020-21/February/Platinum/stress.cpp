#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = uniform_int_distribution<int>(100,200)(rng), q = 100, x, y;
    cout<<n<<" "<<q<<"\n";
    for (int i=1;i<=n;++i)
        cout<<uniform_int_distribution<int>(1,n)(rng)<<" ";
    cout<<"\n";
    for (int i=1;i<=q;++i)
    {
        x=uniform_int_distribution<int>(1,n)(rng);
        y=uniform_int_distribution<int>(1,n)(rng);
        if (x>y)
            swap(x,y);
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}