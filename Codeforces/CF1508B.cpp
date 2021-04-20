#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    ll k;
    cin>>n>>k;
    if (n<=62&&(1LL<<(n-1))<k)
    {
        cout<<"-1\n";
        return;
    }
    --k;
    vector<int> v(n+1);
    iota(v.begin(), v.end(), 0);
    for (int i=max(n-62,1);i<=n;++i)
    {
        for (int j=i;j<=n;++j)
        {
            if (j!=n&&(1LL<<(n-j-1))<=k)
                k-=(1LL<<(n-j-1));
            else
            {
                for (int l=i;l<=j;++l)
                    v[l]=i+j-l;
                i=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<v[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}