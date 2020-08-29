#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=1e6+10;
vector<int> sieve[MAXN];
int c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<MAXN;i+=2)
        sieve[i].push_back(2);
    for (int i=3;i<MAXN;i+=2)
        if (!sz(sieve[i]))
            for (int j=i;j<MAXN;j+=i)
                sieve[j].push_back(i);
    int n,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        for (int j : sieve[k])
            ++c[j];
    }
    bool ok=1;
    for (int i=2;i<MAXN;++i)
        if (c[i]>1)
            ok=0;
    if (ok)
    {
        cout<<"pairwise coprime";
        return 0;
    }
    ok=1;
    for (int i=2;i<MAXN;++i)
        if (c[i]==n)
            ok=0;
    if (ok)
    {
        cout<<"setwise coprime";
        return 0;
    }
    cout<<"not coprime";
    return 0;
}