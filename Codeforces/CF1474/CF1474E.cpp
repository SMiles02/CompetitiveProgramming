#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i=0;i+1<n;++i)
    {
        if (i<n-i-1)
        {
            swap(p[i],p[n-1]);
            ans+=1LL*(n-i-1)*(n-i-1);
        }
        else
        {
            swap(p[i],p[0]);
            ans+=1LL*i*i;
        }
    }
    cout<<ans<<"\n";
    for (int i : p)
        cout<<i<<" ";
    cout<<"\n"<<n-1<<"\n";
    for (int i=n-1;i;--i)
    {
        if (i-1<n-i)
            cout<<i<<" "<<n<<"\n";
        else
            cout<<i<<" 1\n";
    }
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