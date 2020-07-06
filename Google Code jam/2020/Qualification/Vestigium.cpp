#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int x=0;

void solve()
{
    int r=0,c=0,s=0,n;
    cin>>n;
    int a[n][n];
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;++i)
    {
        s+=a[i][i];
        m.clear();
        for (int j=0;j<n;++j)
        {
            if (m[a[i][j]])
            {
                ++r;
                break;
            }
            ++m[a[i][j]];
        }
    }
    for (int j=0;j<n;++j)
    {
        m.clear();
        for (int i=0;i<n;++i)
        {
            if (m[a[i][j]])
            {
                ++c;
                break;
            }
            ++m[a[i][j]];
        }
    }
    cout<<"Case #"<<x<<": "<<s<<" "<<r<<" "<<c<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        ++x;
        solve();
    }
    return 0;
}