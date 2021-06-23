#include <bits/stdc++.h>
using namespace std;

double binpow(double a, int b)
{
    double res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, k;
    cin>>n;
    double ans = 0;
    while (n--)
    {
        cin>>k;
        ans+=2-1/binpow(2,k-1);
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
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