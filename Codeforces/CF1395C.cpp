#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
int a[200];
int b[200];

bool check(int k)
{
    bool ok;
    for (int i=0;i<n;++i)
    {
        ok=0;
        for (int j=0;j<m;++j)
            if (((a[i]&b[j])&k)==(a[i]&b[j]))
                ok=1;
        if (!ok)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans=512;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<m;++i)
        cin>>b[i];
    for (int i=511;i>=0;--i)
        if (check(i))
            ans=i;
    cout<<ans;
    return 0;
}