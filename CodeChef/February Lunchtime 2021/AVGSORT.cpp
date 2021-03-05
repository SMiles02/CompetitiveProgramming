#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    set<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    if (sz(s)==1)
        cout<<"No\n";
    else
    {
        for (int i=1;i<n;++i)
            if (a[i-1]<a[i])
            {
                cout<<"Yes\n";
                return;
            }
        cout<<"No\n";
    }
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