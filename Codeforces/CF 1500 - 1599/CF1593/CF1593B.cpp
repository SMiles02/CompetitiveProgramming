#include <bits/stdc++.h>
using namespace std;

int check(string s, char a, char b)
{
    int rt=0;
    bool fd=0;
    for (int i=(int)(s).size()-1;i>=0;--i)
    {
        if (fd)
        {
            if (s[i]==a)
                return rt;
            ++rt;
        }
        else
        {
            if (s[i]==b)
                fd=1;
            else
                ++rt;
        }
    }
    return 100;
}

void solve()
{
    int ans=100;
    string s;
    cin>>s;
    ans=min(ans,check(s,'0','0'));
    ans=min(ans,check(s,'2','5'));
    ans=min(ans,check(s,'5','0'));
    ans=min(ans,check(s,'7','5'));
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}