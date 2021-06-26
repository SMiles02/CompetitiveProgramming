#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int hsb(int k)
{
    while (__builtin_popcount(k)>1)
        k-=(k&-k);
    return k;
}

vector<array<int,2>> edges[33];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,r,x,z,k,e=0;
    cin>>l>>r;
    x=hsb(r-l+1);
    for (int i=0;;++i)
        if (x==(1<<i))
        {
            k=i;
            break;
        }
    for (int j=2;j<k+3;++j)
    {
        edges[1].push_back({j,l});
        ++e;
    }
    for (int i=2;i<k+2;++i)
        for (int j=i+1;j<k+3;++j)
        {
            edges[i].push_back({j,1<<(i-2)});
            ++e;
        }
    cout<<"YES\n";
    z=r-l;
    if (z)
    {
        cout<<k+3;
        edges[1].push_back({k+3,l});
        ++e;
        for (int i=0;i<=k;++i)
            if ((1<<i)&z)
            {
                z^=(1<<i);
                edges[i+2].push_back({k+3,z+1});
                ++e;
            }
    }
    else
        cout<<k+2;
    cout<<" "<<e<<"\n";
    for (int i=1;i<k+3;++i)
        for (auto j : edges[i])
            cout<<i<<" "<<j[0]<<" "<<j[1]<<"\n";
    return 0;
}