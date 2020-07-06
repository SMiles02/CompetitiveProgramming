#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int test=0;

void solve()
{
    ++test;
    cout<<"Case #"<<test<<": ";
    int n,d,unique=0,twos=0,threes=0;
    cin>>n>>d;
    ll a[n];
    map<ll,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++m[a[i]];
        if (m[a[i]]==1)
            ++unique;
        if (m[a[i]]==2)
        {
            --unique;
            ++twos;
        }
        if (m[a[i]]==3)
        {
            --twos;
            ++threes;
        }
    }
    if (d==2)
    {
        if (twos||threes)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<"1\n";
        }
        return;
    }
    if (threes)
    {
        cout<<"0\n";
        return;
    }
    for (int i=0;i<n;++i)
    {
        if (m[2*a[i]])
        {
            cout<<"1\n";
            return;
        }
    }
    cout<<"2\n";
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