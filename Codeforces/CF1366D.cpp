#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
int ans[500000];
int sieve[10000001];
 
void solve(int k)
{
    ll n,x;
    cin>>n;
    if (!sieve[n])
    {
        cout<<"-1 ";
        ans[k]=-1;
        return;
    }
    x=sieve[n];
    while (!(n%x))
        x*=sieve[n];
    x/=sieve[n];
    if (x==n)
    {
        cout<<"-1 ";
        ans[k]=-1;
        return;
    }
    cout<<x<<" ";
    ans[k]=n/x;
} 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<=10000000;++i)
        if (!sieve[i])
            for (int j=2*i;j<=10000000;j+=i)
                sieve[j]=i;
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        solve(i);
    cout<<"\n";
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    return 0;
}