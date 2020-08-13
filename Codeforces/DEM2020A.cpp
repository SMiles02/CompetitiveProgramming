#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int cur,treeTill,trie[500000][26],endingOf[500000],ending[500000],small,big;
set<int> smols,bigs;

void addNew()
{
    string s;
    cin>>s;
    int i=0;
    for (auto c : s)
    {
        if (trie[i][(c-'a')])
        {
            i=trie[i][(c-'a')];
            continue;
        }
        trie[i][(c-'a')]=++treeTill;
        i=treeTill;
    }
    endingOf[i]=++cur;
    ending[cur]=i;
}

void extend()
{
    int n;
    char c;
    cin>>n;
    cin>>c;
    if (!trie[ending[n]][c-'a'])
        trie[ending[n]][c-'a']=++treeTill;
    endingOf[trie[ending[n]][c-'a']]=++cur;
    ending[cur]=trie[ending[n]][c-'a'];
    bool ok;
    if (smols.find(endingOf[n])!=smols.end())
    {
        ok=1;
        for (int j=0;j<(c-'a');++j)
            if (trie[ending[n]][j])
                ok=0
        if (ok)
        {
            
        }
    }
}

void printMin()
{
    int i=0;
    bool ok;
    while (1)
    {
        ok=0;
        for (int j=0;j<26;++j)
            if (trie[i][j])
            {
                i=trie[i][j];
                ok=1;
                break;
            }
        if (!ok)
        {
            small=endingOf[i];
            smols.insert(endingOf[i]);
            return;
        }
    }
}

void printMax()
{
    int i=0;
    bool ok;
    while (1)
    {
        ok=0;
        for (int j=25;j>=0;--j)
            if (trie[i][j])
            {
                i=trie[i][j];
                ok=1;
                break;
            }
        if (!ok)
        {
            big=endingOf[i];
            bigs.endingOf[i];
            return;
        }
    }
}

void solve()
{
    for (int i=0;i<500000;++i)
    {
        for (int j=0;j<26;++j)
            trie[i][j]=0;
        ending[i]=0;
        endingOf[i]=0;
    }
    treeTill=0;cur=0;smols.clear();bigs.clear();
    int n,q,k;
    cin>>n;
    while (n--)
        addNew();
    printMax();
    printMin();
    cin>>q;
    while (q--)
    {
        cin>>k;
        if (k==1)
            extend();
        else if (k==2)
            printMin();
        else
            printMax();
    }
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