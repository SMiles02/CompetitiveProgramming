#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 1e5+1;
int factor[maxn],entry[maxn],ext[maxn],f[maxn];

void buildFactors()
{
    for (int i=2;i<maxn;++i)
    {
        if (!factor[i])
        {
            factor[i]=i;
            for (int j=2*i;j<maxn;j+=i)
                factor[j]=i;
        }
    }
}

void process(int k, int x)
{
    while (k>1)
    {
        if (entry[factor[k]]==0)
            entry[factor[k]]=x;
        ext[factor[k]]=x;
        k/=factor[k];
    }
    return;
}

void solve()
{
    int n,k;
    cin>>n;
    for (int i=1;i<maxn;++i)
    {
        entry[i]=0;
        ext[i]=0;
        f[i]=0;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        process(k,i);
    }
    for (int i=1;i<maxn;++i)
    {
        ++f[entry[i]];
        --f[ext[i]];
    }
    k=0;
    for (int i=1;i<=n;++i)
    {
        k+=f[i];
        if (k==0)
        {
            cout<<i<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    buildFactors();
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}