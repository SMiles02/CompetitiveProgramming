#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,cur;
string s[2];

void solve()
{
    cin>>n;
    cin>>s[0];
    cin>>s[1];
    cur=0;
    for (int i=0;i<n;++i)
    {       
        if ((s[cur][i]-'0')>2)
        {
            cur++;
            cur%=2;
            if ((s[cur][i]-'0')<3)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    if (cur)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        solve();
    }
    return 0;
}