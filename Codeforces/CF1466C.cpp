#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=sz(s),ans=0;
    for (int i=1;i<n;++i)
    {
        if (s[i]==s[i-1])
        {
            ++ans;
            s[i]='?';
            continue;
        }
        if (i>1&&s[i]==s[i-2])
        {
            s[i]='?';
            ++ans;
        }
    }
    cout<<ans<<"\n";
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