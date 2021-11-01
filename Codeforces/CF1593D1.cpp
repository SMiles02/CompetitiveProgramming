#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n,g=0;
    cin>>n;
    int a[n];
    cin>>a[0];
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        g=gcd(g,abs(a[i]-a[i-1]));
    }
    if (g==0)
        g=-1;
    cout<<g<<"\n";
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