#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int stringCompare(string s, string t, int n)
{
    for (int i=0;i<n;++i)
    {
        if (s[i]<t[i])
        {
            return 0;
        }
        if (t[i]<s[i])
        {
            return 1;
        }
    }
    return 0;
}

void solve()
{
    int n,k;
    string s,t,ans;
    cin>>n;
    cin>>s;
    k=1;
    ans=s;
    for (int start=1;start<n;++start)
    {
        t.clear();
        for (int i=start;i<n;++i)
        {
            t+=s[i];
        }
        if ((n-start)%2)
        {
            for (int i=start-1;i>-1;--i)
            {
                t+=s[i];
            }
        }
        else
        {
            for (int i=0;i<start;++i)
            {
                t+=s[i];
            }
        }
        if (stringCompare(ans,t,n))
        {
            ans=t;
            k=start+1;
        }
    }
    cout<<ans<<"\n"<<k<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}