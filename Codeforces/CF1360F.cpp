#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;

int diff(string s, string t)
{
    int c=0;
    for (int i=0;i<m;++i)
        if (s[i]!=t[i])
            ++c;
    return c;
}

bool check(string s, set<string> se)
{
    for (auto it=se.begin();it!=se.end();++it)
        if (diff(s,*it)>1)
            return 0;
    return 1;
}

void solve()
{
    
    cin>>n>>m;
    set<string> se;
    string s;
    for (int i=0;i<n;++i)
    {
        cin>>s;
        se.insert(s);
    }
    if (sz(se)==1)
    {
        cout<<*se.begin()<<"\n";
        return;
    }
    s=*se.begin();
    if (check(s,se))
    {
        cout<<s<<"\n";
        return;
    }
    for (int i=0;i<m;++i)
    {
        s=*se.begin();
        for (char c='a';c<='z';++c)
        {
            s[i]=c;
            if (check(s,se))
            {
                cout<<s<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
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