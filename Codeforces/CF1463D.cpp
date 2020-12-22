#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
bitset<500000> b; 

void solve()
{
    int p,q,k;
    cin>>n;
    p=0;q=n;
    for (int i=0;i<=2*n;++i)
        b[i]=0;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        b[k]=1;
    }
    k=0;
    for (int i=1;i<=2*n;++i)
    {
        if (b[i])
        {
            if (k)
                --k;
            else
                --q;
        }
        else
            ++k;
    }
    k=0;
    for (int i=2*n;i;--i)
    {
        if (b[i])
        {
            if (k)
                --k;
            else
                ++p;
        }
        else
            ++k;
    }
    cout<<q-p+1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}