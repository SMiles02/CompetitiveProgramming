#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
int frogScores[101];
int frogLead[101];

void checker()
{
    int cur=0,broken=0;
    for (int i=1;i<=n;++i)
    {
        if (frogScores[i]>frogScores[cur])
        {
            cur=i;
            broken=0;
        }
        else if (frogScores[i]==frogScores[cur])
        {
            broken=1;
        }
    }
    if (!broken)
    {
        ++frogLead[cur];
    }
    return;
}

int main()
{
    int m,a,b,maxi;
    cin>>n;
    cin>>m;
    while (m--)
    {
        checker();
        cin>>a>>b;
        frogScores[a]+=b;
    }
    maxi=1;
    for (int i=1;i<=n;++i)
    {
        if (frogLead[i]>frogLead[maxi])
        {
            maxi=i;
        }
    }
    cout<<maxi;
    return 0;
}