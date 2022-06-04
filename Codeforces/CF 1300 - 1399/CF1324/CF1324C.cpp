#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,maxi=0,cur=0;
    string s;
    cin>>s;
    n=sz(s);
    if (s[0]=='L')
    {
        cur=1;
        maxi=1;
    }
    for (int i=1;i<n;++i)
    {
        if (s[i]=='L')
        {
            ++cur;
        }
        else
        {
            cur=0;
        }
        maxi=max(maxi,cur);
    }
    cout<<maxi+1<<"\n";
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