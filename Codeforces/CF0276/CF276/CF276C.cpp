#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,cur=0;
    ll ans=0;
    cin>>n>>q;
    ll a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int differences[n+1]={};
    int occurences[n];
    while (q--)
    {
        cin>>l>>r;
        ++differences[l-1];
        --differences[r];
    }
    for (int i=0;i<n;++i)
    {
        cur+=differences[i];
        occurences[i]=cur;
    }
    sort(occurences,occurences+n);
    for (int i=0;i<n;++i)
    {
        ans+=(a[i]*occurences[i]);
    }
    cout<<ans;
    return 0;
}