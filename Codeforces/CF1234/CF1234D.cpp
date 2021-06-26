#include <bits/stdc++.h>
using namespace std;

set<int> s[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y,z;
    string t;
    char c;
    cin>>t;
    n=t.size();
    for (int i=0;i<n;++i)
        s[t[i]-'a'].insert(i+1);
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        if (x==1)
        {
            cin>>c;
            s[t[y-1]-'a'].erase(s[t[y-1]-'a'].find(y));
            s[c-'a'].insert(y);
            t[y-1]=c;
        }
        else
        {
            cin>>z;
            x=0;
            for (int i=0;i<26;++i)
                if (s[i].lower_bound(y)!=s[i].end()&&*s[i].lower_bound(y)<=z)
                    ++x;
            cout<<x<<"\n";
        }
    }
    return 0;
}