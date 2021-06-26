#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,q,l,r;
string s;
map<int,map<char,int>> characters;

void solve()
{
    cin>>l>>r;
    if (l==r)
    {
        cout<<"Yes\n";
        return;
    }
    for (char x='a';x<='z';++x)
    {
        //cout<<x<<" "<<characters[r][x]-characters[l-1][x]<<"\n";
        if (characters[r][x]-characters[l-1][x]==r-l+1)
        {
            cout<<"No\n";
            return;
        }
    }
    if (s[l-1]==s[r-1])
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    cin>>q;
    n=sz(s);
    map<char,int> m;
    for (int i=0;i<n;++i)
    {
        characters[i]=m;
        ++m[s[i]];
    }
    characters[n]=m;
    while (q--)
    {
        solve();
    }
    return 0;
}