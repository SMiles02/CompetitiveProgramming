#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,cur=0,ans=0;
    string s;
    cin>>n>>x;
    cin>>s;
    for (int i=0;i<2*n;++i)
    {
        if (s[i]=='0')
        {
            ++cur;
        }
        else
        {
            --cur;
        }
        if (cur==x)
        {
            ++ans;
        }
    }
    if (cur)
    {

        return;
    }
    if (ans)
    {

        return;
    }
    if (x)
    {
        
    }
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