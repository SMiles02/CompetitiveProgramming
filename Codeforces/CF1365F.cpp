#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int a[500];
int b[500];

void solve()
{
    int n;
    cin>>n;
    map<pair<int,int>,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    for (int i=0;i<n;++i)
        ++m[{a[i],a[n-1-i]}];
    for (int i=0;i<n;++i)
    {
        if (m[{b[i],b[n-i-1]}])
            --m[{b[i],b[n-i-1]}];
        else
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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