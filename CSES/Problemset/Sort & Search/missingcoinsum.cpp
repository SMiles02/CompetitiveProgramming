#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    if (a[0]>1)
    {
        cout<<1;
        return 0;
    }
    ll s=1;
    for (int i=1;i<n;++i)
    {
        if (s+1<a[i])
        {
            cout<<s+1;
            return 0;
        }
        s+=a[i];
    }
    cout<<s+1;
    return 0;
}