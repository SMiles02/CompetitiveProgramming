#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int N=1e7+1;
ll sieve[N];
ll ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;++i)
        for (int j=i;j<N;j+=i)
            ++sieve[j];
    for (int i=1;i<N;++i)
        ans[i]=ans[i-1]+(sieve[i]*i);
    int n;
    cin>>n;
    cout<<ans[n];
    return 0;
}