#include <bits/stdc++.h>
using namespace std;

int id[51];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (!id[x])
            id[x]=i;
    }
    while (q--)
    {
        cin>>x;
        cout<<id[x]<<" ";
        for (int i=1;i<=50;++i)
            if (id[i]<id[x])
                ++id[i];
        id[x]=1;
    }
    return 0;
}