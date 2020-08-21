#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string ans;

void addZ(string s)
{
    for (int i=0;i<4-sz(s);++i)
        ans+='0';
    ans+=s;
    ans+=":";
}

void solve()
{
    string s,cur="";int spec=39;
    ans.clear();
    cin>>s;
    for (int i=0;i<sz(s);++i)
    {
        if (s[i]==':')
        {
            if (0<=i-1&&s[i-1]==':')
            {
                spec=sz(ans);
            }
            else
            {
                addZ(cur);
            }
            cur.clear();
        }
        else
            cur+=s[i];
    }
    addZ(cur);
    ans.pop_back();
    //cout<<sz(ans)<<"\n";
    for (int i=0;i<spec;++i)
        cout<<ans[i];
    for (int i=0;i<39-sz(ans);i+=5)
        cout<<"0000:";
    for (int i=spec;i<sz(ans);++i)
        cout<<ans[i];
    cout<<"\n";
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