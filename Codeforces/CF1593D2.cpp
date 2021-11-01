#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+1;
bitset<N> b;

void solve()
{
    b.reset();
    int n,ans=1;
    cin>>n;
    int a[n];
    map<int,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i+n/2-1<n;++i)
        if (a[i]==a[i+n/2-1])
        {
            cout<<"-1\n";
            return;
        }
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
            b[a[i]-a[j]]=1;
    for (int i=1;i<N;++i)
        for (int j=i*2;j<N;j+=i)
            b[i]=b[i]|b[j];
    for (int i=2;i<=2e6;++i)
        if (b[i])
        {
            for (int j=0;j<n;++j)
                if (++m[((a[j]%i)+i)%i]==n/2)
                    ans=i;
            m.clear();
        }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}