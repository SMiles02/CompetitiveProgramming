#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int sieve[1000001];
int prefix[1000001];

void solve()
{
    int n;
    cin>>n;
    if (n==1)
        cout<<0;
    else if (n==2)
        cout<<1;
    else
        cout<<prefix[n]+n-3;
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<1000001;++i)
        if (!sieve[i])
            for (int j=2*i;j<1000001;j+=i)
                sieve[j]=1;
    for (int i=2;i<1000001;++i)
        prefix[i]=prefix[i-1]+1-sieve[i];
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}