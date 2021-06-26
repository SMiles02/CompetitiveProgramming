#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,ans=0;
    string s,t;
    cin>>s;
    cin>>t;
    n=sz(s);
    k=sz(t);
    map<int,map<char,int>> m;
    map<char,int> next;
    for (int i=n-1;i+1;--i)
    {
        m[i+1]=next;
        next[s[i]]=i+1;
    }
    m[0]=next;
    int cur=0;
    for (int i=0;i<k;++i)
    {
        if (m[cur][t[i]]==0)
        {
            cur=0;
            ++ans;
        }
        //cout<<cur<<" "<<ans<<" "<<t[i]<<"\n";
        if (m[cur][t[i]]==0)
        {
            cout<<"-1\n";
            return;
        }
        cur=m[cur][t[i]];
    }
    cout<<ans+1<<"\n";
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