#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,m,k,biggestRemoved=-1,ans;
    cin>>n>>m;
    ans=m;
    map<int,int> a;
    int b[m];
    for (int i=0;i<n;++i)
    {
        cin>>k;
        a[k]=i;
    }
    for (int i=0;i<m;++i)
    {
        cin>>b[i];
        if (a[b[i]]>biggestRemoved)
        {
            biggestRemoved=a[b[i]];
            ans+=(2*(biggestRemoved-i));
        }
        //cout<<"ans: "<<ans<<"\n";
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}