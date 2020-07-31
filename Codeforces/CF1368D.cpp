#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[20];
ll b[200000],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        for (int j=0;j<20;++j)
            if (k&(1<<j))
            {
                b[a[j]]+=(1<<j);
                ++a[j];
            }
    }
    for (int i=0;i<n;++i)
        ans+=(b[i]*b[i]);
    cout<<ans;
    return 0;
}