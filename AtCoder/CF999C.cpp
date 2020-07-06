#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
string s,alpha="abcdefghijklmnopqrstuvwxyz";
map<char,vector<int>> m;

void solve()
{
    for (int i=0;i<26;++i)
    {
        if (sz(m[alpha[i]]))
        {
            s[m[alpha[i]].back()]='.';
            m[alpha[i]].pop_back();
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>n>>k;
    cin>>s;
    for (int i=n-1;i>-1;--i)
    {
        m[s[i]].push_back(i);
    }
    while (k)
    {
        solve();
        --k;
    }
    for (int i=0;i<n;++i)
    {
        if (s[i]!='.')
        {
            cout<<s[i];
        }
    }
    return 0;
}