#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    vector<int> v,w;
    for (int i=1;i<=n;++i)
        v.push_back(i);
    while (k>0)
    {
        if (sz(v)-1<=k)
        {
            k-=sz(v)-1;
            w.push_back(v.back());
            v.pop_back();
        }
        else
            for (int i=sz(v)-1;k;--i,--k)
                swap(v[i],v[i-1]);
    }
    for (int i : w)
        cout<<i<<" ";
    for (int i : v)
        cout<<i<<" ";
    return 0;
}