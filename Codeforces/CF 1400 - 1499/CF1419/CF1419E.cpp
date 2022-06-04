#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int rt = 31625;
int n,k,primeDivisors[1344];
vector<int> primes,cur,factors;
bitset<rt> sieve;
bitset<1344> done,contains[9];

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void precalc()
{
    primes.push_back(2);
    for (int i=3;i<rt;i+=2)
        if (!sieve[i])
        {
            primes.push_back(i);
            for (int j=i*2;j<rt;j+=i)
                sieve[j]=1;
        }
}

void rec(int i, int c, int p)
{
    if (i>=k)
    {
        if (c>1)
        {
            for (int j=0;j<k;++j)
            {
                if (c%cur[j]==0)
                    contains[j][sz(factors)]=1;
                else
                    contains[j][sz(factors)]=0;
            }
            primeDivisors[sz(factors)]=p;
            factors.push_back(c);
        }
        return;
    }
    rec(i+1,c,p);
    for (ll j=cur[i];n%j==0;j*=cur[i])
        rec(i+1,c*j,p+1);
}

void solve()
{
    int m,x=0;
    cin>>n;
    m=n;
    cur.clear();
    for (int i : primes)
        if (m%i==0)
        {
            cur.push_back(i);
            while (m%i==0)
                m/=i;
        }
    if (m>1)
        cur.push_back(m);
    factors.clear();
    k=cur.size();
    rec(0,1,0);
    if (sz(cur)==1)
    {
        for (int i : factors)
            cout<<i<<" ";
        cout<<"\n0\n";
        return;
    }
    for (int i=0;i<1344;++i)
        done[i]=0;
    vector<int> v;
    vector<pii> w;
    v.push_back(n);
    int l=sz(factors),ans=0;
    for (int i=0;i<l;++i)
        if (factors[i]==n)
        {
            done[i]=1;
            break;
        }
    for (int i=0;i<k;++i)
    {
        w.clear();
        //cout<<cur[i]<<"\n";
        for (int j=0;j<l;++j)
            if (!done[j])
            {
                x=0;
                for (int ij=i+1;ij<k;++ij)
                    if (contains[ij][j])
                    {
                        //cout<<factors[j]<<" contains "<<cur[ij]<<"\n";
                        ++x;
                    }
                //cout<<factors[j]<<" "<<x<<"!\n";
                if (x==0)
                {
                    done[j]=1;
                    w.push_back({primeDivisors[j],factors[j]});
                }
            }
        sort(w.rbegin(), w.rend());
        if (gcd(v.back(),w[0].second)==1)
            ++ans;
        for (auto i : w)
        {
            //cout<<"inserting "<<i.second<<"\n";
            v.push_back(i.second);
        }
    }
    for (int i : v)
        cout<<i<<" ";
    cout<<"\n"<<ans<<"\n";
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}