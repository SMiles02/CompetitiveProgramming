#include <bits/stdc++.h>
using namespace std;

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m;
    while (n--)
    {
        for (int i=0;i<m;++i)
        {
            cin>>k;
            if ((i+n)&1)
                cout<<"720720 ";
            else
                cout<<720720-binpow(k,4)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}