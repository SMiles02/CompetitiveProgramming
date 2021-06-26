#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

int sq(int x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,c;
    cin>>n;
    for (int x=1;x<100;++x)
        for (int y=1;y<100;++y)
            for (int z=1;z<100;++z)
            {
                a=sq(x)+sq(y);
                b=sq(y)+sq(x+z);
                c=sq(z)+sq(2*y);
                if (sq(sqrt(a))==a)
                    if (sq(sqrt(b))==b)
                        if (sq(sqrt(c))==c)
                            cout<<x<<" "<<y<<" "<<z<<"\n";
            }
    cout<<"done\n";
    return 0;
}