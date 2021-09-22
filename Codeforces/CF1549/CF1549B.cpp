#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,ans=0;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    for (int i=0;i<n;++i)
        if (t[i]=='1')
        {
            if (s[i]=='0')
                ++ans;
            else if (i>0&&s[i-1]=='1')
                ++ans;
            else if (i+1<n&&s[i+1]=='1')
            {
                ++ans;
                s[i+1]='?';
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