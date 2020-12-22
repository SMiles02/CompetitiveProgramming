#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int ans=100,cur;
    for (int i=0;i<(1<<(sz(s)))-1;++i)
    {
        cur=0;
        for (int j=0;j<sz(s);++j)
            if (!(i&(1<<j)))
                cur+=(s[j]-'0');
        if (cur%3==0)
            ans=min(ans,__builtin_popcount(i));
    }
    if (ans==100)
        ans=-1;
    cout<<ans;
    return 0;
}