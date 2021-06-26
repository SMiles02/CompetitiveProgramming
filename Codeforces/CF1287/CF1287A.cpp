#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int k,found=0,cur=0,maxi=0;
    string s;
    cin>>k;
    cin>>s;
    for (int i=0;i<k;++i)
    {
        if (s[i]=='A')
        {
            found=1;
        }
        if (found)
        {
            if (s[i]=='A')
            {
                cur=0;
            }
            else
            {
                ++cur;
            }
        }
        maxi=max(maxi,cur);
    }
    cout<<maxi<<"\n";
    return;
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