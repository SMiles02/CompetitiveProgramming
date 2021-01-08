#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e6+1;
int pF[mn],res[mn];

void sieve()
{
    for (int i=2;i<mn;++i)
        if (pF[i]==0)
        {
            pF[i]=i;
            for (int j=2*i;j<mn;j+=i)
                pF[j]=i;
        }
    res[1]=1;
    int k;
    for (int i=2;i<mn;++i)
    {
        k=i/pF[i];
        if (res[k]%pF[i])
            res[i]=res[k]*pF[i];
        else
            res[i]=res[k]/pF[i];
    }
}

void solve()
{
    int n,a1=0,a2=0;
    cin>>n;
    map<int,int> m1,m2;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]=res[a[i]];
        a1=max(a1,++m1[a[i]]);
    }
    for (int i=0;i<n;++i)
    {
        if (m1[a[i]]&1)
            a[i]=a[i];
        else
            a[i]=1;
        a2=max(a2,++m2[a[i]]);
    }
    cin>>n;
    ll k;
    while (n--)
    {
        cin>>k;
        if (k==0)
            cout<<a1<<"\n";
        else
            cout<<a2<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    sieve();
    while (n--)
        solve();
    return 0;
}