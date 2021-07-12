#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    ll ans[n];
    array<int,2> a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0];
        a[i][1]=i;
        ans[i]=k/n;
    }
    sort(a,a+n);
    k%=n;
    for (int i=0;i<n;++i)
        if (k)
        {
            --k;
            ++ans[a[i][1]];
        }
    for (int i=0;i<n;++i)
        cout<<ans[i]<<"\n";
    return 0;
}