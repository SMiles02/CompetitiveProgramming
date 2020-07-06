#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,g,b,k;
    cin>>n>>g>>b;
    if (g>=b||n<=g)
    {
        cout<<n<<"\n";
        return;
    }
    k=(n+1)/2;
    cout<<max(((k-1)/g)*(g+b)+(k-((k-1)/g)*g),n)<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}