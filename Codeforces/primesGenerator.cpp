#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool sieve[10000000];
vector<int> v;
map<int,bool> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=4;i<10000000;i+=2)
        sieve[i]=1;
    for (int i=3;i<10000000;i+=2)
        if (!sieve[i])
        {
            if (i>7000000)
                v.push_back(i);
            for (int j=3*i;j<10000000;j+=(2*i))
                sieve[j]=1;
        }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cout<<"vector<int> primes = {";
    int p,done=0;
    while (done<20)
    {
        p=v[uniform_int_distribution<int>(1,sz(v))(rng)-1];
        while (m[p])
            p=v[uniform_int_distribution<int>(1,sz(v))(rng)-1];
        if (done)
            cout<<",";
        cout<<p;
        m[p]=1;
        ++done;
    }
    cout<<"};";
    return 0;
}