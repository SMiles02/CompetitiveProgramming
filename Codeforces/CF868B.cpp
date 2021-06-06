#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

const int N = 12*60*60;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h,m,s,t1,t2,H,M,S,T1,T2;
    cin>>h>>m>>s>>t1>>t2;
    S=(s*N)/60;
    M=(m*N)/60+s*12;
    h%=12;
    H=(h*N)/12+m*60+s;
    cout<<H<<" "<<M<<" "<<S<<"\n";
    return 0;
}