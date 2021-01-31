#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int group[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c;
    cin>>n;
    if (n%3==1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    c=(n*(n+1))/6-1;
    for (int i=n;i;--i)
        if (!group[i]&&i<=c)
        {
            c-=i;
            group[i]=1;
        }
    c=(n*(n+1))/6;
    for (int i=n;i;--i)
        if (!group[i]&&i<=c)
        {
            c-=i;
            group[i]=2;
        }
    for (int i=1;i<=n;++i)
    {
        if (group[i])
            cout<<group[i]<<" ";
        else
            cout<<"3 ";
    }
    return 0;
}