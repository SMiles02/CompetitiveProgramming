#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    string s,t;
    vector<int> v,w;
    cin>>s;
    cin>>t;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='0')
            v.push_back(i);
        if (t[i]=='0')
            w.push_back(i);
    }
    if (sz(v)!=sz(w))
    {
        cout<<-1;
        return 0;
    }
    for (int i=0;i<sz(v);++i)
        if (v[i]!=w[i])
            ++ans;
    cout<<ans;
    return 0;
}