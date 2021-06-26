#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,i;
vector<int> v;

int finder()
{
    for (int j=i+1;j<n;++j)
    {
        if (v[i]==v[j])
        {
            return j;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    n*=2;
    int k,ans=0;
    for (i=0;i<n;++i)
    {
        cin>>k;
        v.push_back(k);
    }
    for (i=0;i<n;i+=2)
    {
        k=finder();
        for (int j=k;j>i+1;--j)
        {
            ++ans;
            swap(v[j],v[j-1]);
        }
    }
    cout<<ans;
    return 0;
}