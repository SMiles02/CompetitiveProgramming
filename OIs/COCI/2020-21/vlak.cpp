#include <bits/stdc++.h>
using namespace std;

const int mn = 3e5;
int trie[mn],nextOne[26][mn],cur,lt[mn];
bitset<mn> reachable[2],winnable[2];

void add(int x)
{
    string s;
    cin>>s;
    int c=0,n=s.size();
    for (int i=0;i<n;++i)
    {
        if (nextOne[s[i]-'a'][c]==0)
        {
            nextOne[s[i]-'a'][c]=++cur;
            lt[cur]=i+1;
        }
        c=nextOne[s[i]-'a'][c];
        reachable[x][c]=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    reachable[0][0]=1;
    reachable[1][0]=1;
    while (n--)
        add(0);
    cin>>n;
    while (n--)
        add(1);
    for (int i=cur;i+1;--i)
    {
        if (lt[i]&1) //second player (Emilia) to move
        {
            if (reachable[1][i])
            {
                if (!reachable[0][i])
                    winnable[1][i]=1;
                for (int j=0;j<26;++j)
                    if (nextOne[j][i])
                        if (winnable[0][nextOne[j][i]]==0)
                            winnable[1][i]=1;
            }
        }
        else
        {
            if (reachable[0][i])
            {
                if (!reachable[1][i])
                    winnable[0][i]=1;
                for (int j=0;j<26;++j)
                    if (nextOne[j][i])
                        if (winnable[1][nextOne[j][i]]==0)
                            winnable[0][i]=1;
            }
        }
    }
    if (winnable[0][0])
        cout<<"Nina";
    else
        cout<<"Emilija";
    return 0;
}