#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        if (m[a[i]])
        {
            if ((m[a[i]]==1&&a[i-1]!=a[i])||m[a[i]]>1)
            {
                cout<<"YES\n";
                return;
            }
        }
        ++m[a[i]];
    }
    cout<<"NO\n";
    return;
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