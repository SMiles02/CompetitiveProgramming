#include <bits/stdc++.h>
using namespace std;

int n;
string s[200000];

int check(char c)
{
    int rtn=0,cur=0;
    vector<int> v(n);
    for (int i=0;i<n;++i)
    {
        int x=0,y=0;
        for (auto j : s[i])
        {
            if (j==c)
                ++x;
            else
                ++y;
        }
        v[i]=x-y;
    }
    sort(v.rbegin(), v.rend());
    for (int i : v)
    {
        cur+=i;
        if (cur<=0)
            return rtn;
        ++rtn;
    }
    return rtn;
}

void solve()
{
    int ans=0;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (char c = 'a'; c <= 'e' ; ++c)
        ans=max(check(c),ans);
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