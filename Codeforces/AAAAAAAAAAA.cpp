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

bool isPrime(int n)
{
    for (int i=2;i*i<=n;++i)
        if (n%i==0)
            return 0;
    return 1;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=1000;++i)
        if (isPrime(i))
            for (int j=2;j<=1000;++j)
                if (isPrime(j)&&isPrime(i+j))
                    for (int k=2;k<=1000;++k)
                        if (isPrime(k)&&isPrime(i+j+k)&&isPrime(j+k))
                        {
                            cout<<i<<" "<<j<<" "<<k<<"\n";
                        }
    cout<<"donezo\n";
    return 0;
}