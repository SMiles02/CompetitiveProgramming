#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
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

int completed[1048576];
int remaind[1048576];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,m;
    cin>>n>>x;
    int w[n];
    for (int i=0;i<n;++i)
        cin>>w[i];
    m=binpow(2,n);
    for (int i=1;i<m;++i)
        completed[i]=100;
    for (int i=1;i<m;++i)
        for (int j=0;j<n;++j)
            if (i&(1<<j))
            {
                if (remaind[i-(1<<j)]+w[j]>x)
                {
                    if ((completed[i-(1<<j)]+1<completed[i])||(completed[i-(1<<j)]+1==completed[i]&&w[j]<remaind[i]))
                    {
                        completed[i]=completed[i-(1<<j)]+1;
                        remaind[i]=w[j];
                    }
                }
                else if (remaind[i-(1<<j)]+w[j]==x)
                {
                    if (completed[i-(1<<j)]+1<completed[i])
                    {
                        completed[i]=completed[i-(1<<j)]+1;
                        remaind[i]=0;
                    }
                }
                else
                {
                    if ((completed[i-(1<<j)]<completed[i])||(completed[i-(1<<j)]==completed[i]&&(remaind[i-(1<<j)]+w[j])%x<remaind[i]))
                    {
                        completed[i]=completed[i-(1<<j)];
                        remaind[i]=remaind[i-(1<<j)]+w[j];
                    }
                }
            }
    cout<<completed[m-1]+min(remaind[m-1],1);
    return 0;
}