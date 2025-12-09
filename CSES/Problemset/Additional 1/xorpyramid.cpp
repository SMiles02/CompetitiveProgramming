#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;++i)
        cin>>v[i];
    if ((n&1)==0)
    {
        for (int i=0;i+1<n;++i)
            v[i]^=v[i+1];
        --n;
    }
    for (int i=17;i;--i)
        if (n&(1<<i))
        {
            vector<int> w(n^(1<<i));
            for (int j=0;j<(n^(1<<i));++j)
                w[j]=v[j]^v[j^(1<<i)];
            v=w;
            n^=(1<<i);
        }
    cout<<v[0];
    return 0;
}