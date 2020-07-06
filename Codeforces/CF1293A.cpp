#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,s,k,x,i;
    cin>>n>>s>>k;
    map<int,int> m;
    while (k--)
    {
        cin>>x;
        ++m[abs(x-s)];
    }
    if (!m[0])
    {
        cout<<"0\n";
        return;
    }
    for (i=1;i<2000;++i)
    {
        if (s+i>n||s-i<1)
        {
            break;
        }
        if (m[i]<2)
        {
            cout<<i<<"\n";
            return;
        }
    }
    for (i=i;i<2000;++i)
    {
        if (m[i]<1)
        {
            cout<<i<<"\n";
            return;
        }
    }
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