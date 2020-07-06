#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

int n;
int segtree[500000];



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,p,b,cur,parity;
    cin>>n>>m;
    n=binpow(2,n);
    for (int i=n;i<2*n;++i)
    {
        cin>>segtree[i];
    }
    parity=1;
    cur=n;
    for (int i=n-1;i;--i)
    {
        if (parity) segtree[i]=segtree[i*2]|segtree[i*2+1];
        else segtree[i]=segtree[i*2]^segtree[i*2+1];
        if (i*2==cur)
        {
            cur=i;
            parity=1-parity;
        }
    }
    while (m--)
    {
        cin>>p>>b;
        p=n+p-1;
        segtree[p]=b;
        p/=2;parity=1;
        while (p)
        {
            if (parity) segtree[p]=segtree[p*2]|segtree[p*2+1];
            else segtree[p]=segtree[p*2]^segtree[p*2+1];
            p/=2;
            parity=1-parity;
        }
        cout<<segtree[1]<<"\n";
    }
    return 0;
}