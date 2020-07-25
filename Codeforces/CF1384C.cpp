#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string alpha="abcdefghijklmnopqrstuvwxyz";

void solve()
{
    int n,ans=0;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    set<int> toDo[20];
    bool canReach[20][20];
    for (int i=0;i<20;++i)
    {
        for (int j=0;j<i;++j)
            canReach[i][j]=0;
        for (int j=i+1;j<20;++j)
            canReach[i][j]=0;
        canReach[i][i]=1;
    }
    for (int i=0;i<n;++i)
    {
        if (s[i]>t[i])
        {
            cout<<"-1\n";
            return;
        }
        toDo[(s[i]-'a')].insert((t[i]-'a'));
    }
    for (int i=19;i+1;--i)
    {
        for (int j : toDo[i])
            if (!canReach[i][j])
            {
                ++ans;
                for (int l=i+1;l<20;++l)
                    if (canReach[l][j])
                    {
                        for (int k=0;k<20;++k)
                            if (canReach[l][k])
                                canReach[i][k]=1;
                        break;
                    }
            }
    }
    cout<<ans<<"\n";
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