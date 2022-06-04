#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n,a,b,ct=1;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    for (int i=1;i<n;++i)
        if (s[i]!=s[i-1])
            ++ct;
    if (b>=0)
        cout<<(a+b)*n<<"\n";
    else
        cout<<n*a+(ct/2+1)*b<<"\n";
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}