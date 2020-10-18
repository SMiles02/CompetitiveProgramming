#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int maxn=1e5+1;
int q,n;
vector<int> primes;
bitset<maxn> sieve;

void findPrimes()
{
    if (2<=n)
        primes.push_back(2);
    for (int i=3;i<=n;i+=2)
        if (!sieve[i])
        {
            primes.push_back(i);
            for (int j=i*3;j<=n;j+=(2*i))
                sieve[j]=1;
        }
}

void stall()
{
    int x=0;
    while (1)
        ++x;
}

void didOne()
{
    ++q;
    if (q>9995)
        stall();
}

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

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int k,l,r,m;
    cin>>n;
    ll cur=1,x;
    findPrimes();
    shuffle(primes.begin(), primes.end(), rng);
    for (int i : primes)
    {
        if (cur*i>n)
            continue;
        cout<<"B "<<i<<endl;
        cin>>k;
        didOne();
        if (!k)
            continue;
        cout<<"A "<<i<<endl;
        didOne();
        cin>>k;
        if (!k)
            continue;
        x=cur*i;
        for (int j=2;j<18;++j)
        {
            x*=i;
            if (x>n)
            {
                r=j-1;
                break;
            }
        }
        l=1;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            cout<<"A "<<binpow(i,m)<<endl;
            didOne();
            cin>>k;
            if (k==1)
                l=m;
            else
                r=m-1;
        }
        cur*=binpow(i,l);
    }
    cout<<"C "<<cur<<endl;
    return 0;
}