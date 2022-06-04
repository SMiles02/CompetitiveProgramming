#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,unique=0,same=0,x;
    cin>>n;
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        ++m[x];
        if (m[x]==1)
        {
            ++unique;
        }
        else
        {
            same=max(same,m[x]-1);
        }
    }
    if (unique>same)
    {
        --unique;
        ++same;
    }
    cout<<min(same,unique)<<"\n";
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