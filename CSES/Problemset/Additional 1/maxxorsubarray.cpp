#include <bits/stdc++.h>
using namespace std;

int trie[6400000][2],d;

void add(int x)
{
    int c=0;
    for (int i=29;i>=0;--i)
    {
        if (!trie[c][min((1<<i)&x,1)])
            trie[c][min((1<<i)&x,1)]=++d;
        c=trie[c][min((1<<i)&x,1)];
    }
    trie[c][0]=x;
}

int query(int x)
{
    int c=0;
    for (int i=29;i>=0;--i)
    {
        if ((1<<i)&x)
        {
            if (trie[c][0])
                c=trie[c][0];
            else
                c=trie[c][1];
        }
        else
        {
            if (trie[c][1])
                c=trie[c][1];
            else
                c=trie[c][0];
        }
    }
    return trie[c][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c=0,ans=0,k;
    cin>>n;
    add(0);
    for (int i=0;i<n;++i)
    {
        cin>>k;
        c^=k;
        ans=max(ans,c^query(c));
        add(c);
    }
    cout<<ans;
    return 0;
}