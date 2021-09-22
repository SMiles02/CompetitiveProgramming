#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s,t="!";
    cin>>s;
    for (auto i : s)
        if (i!='F'&&i!=t.back())
            t+=i;
    cout<<max(0,sz(t)-2)<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}