#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<ll> v;

void solve()
{
    int n;
    cin>>n;
    for (int i=80;i>=0;--i)
        if (n>=v[i])
        {
            cout<<i+1<<"\n";
            return;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<10;++i)
        for (ll j=i;j<1000000000;j=j*10+i)
            v.push_back(j);
    sort(v.begin(), v.end());
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}