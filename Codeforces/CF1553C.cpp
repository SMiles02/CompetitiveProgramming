#include <bits/stdc++.h>
using namespace std;

int ans;
string s;

void rec(int k)
{
    if (k==10)
    {
        int x=5,y=5,a=0,b=0;
        for (int i=0;i<10;++i)
        {
            if (i&1)
            {
                b+=(s[i]-'0');
                --y;
            }
            else
            {
                a+=(s[i]-'0');
                --x;
            }
            if (a>b+y||b>a+x)
                ans=min(ans,i+1);
        }
        return;
    }
    if (s[k]=='?')
    {
        s[k]='1';
        rec(k+1);
        s[k]='0';
        rec(k+1);
        s[k]='?';
        return;
    }
    rec(k+1);
}

void solve()
{
    ans=10;
    cin>>s;
    rec(0);
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