#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for (int i=0;i<n;++i)
    {
        if (a[i]<b[i])
        {
            if (!m[1])
            {
                cout<<"NO\n";
                return;
            }
        }
        if (a[i]>b[i])
        {
            if (!m[-1])
            {
                cout<<"NO\n";
                return;
            }
        }
        ++m[a[i]];
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}