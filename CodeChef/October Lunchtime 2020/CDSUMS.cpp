#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 50005001;
bitset<mn> b;

void solve()
{
    int l,r;
    cin>>l>>r;
    if (l==1)
    {
        cout<<((ll)r*((ll)r+1))/2<<"\n";
        return;
    }
    b.reset();
    b[0]=1;
    for (int i=l;i<=r;++i)
        for (int j=mn-1;j>=i;--j)
            if (b[j-i])
                b[j]=1;
    cout<<b.count()-1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}