#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[300001][2];

void solve()
{
    int n,largest=0,cur=0,lastInd=0,k;
    cin>>n;
    set<int> s;
    for (int i=1;i<=n;++i)
    {
        a[i][0]=0;
        a[i][1]=0;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        s.insert(k);
        if (!a[k][0]) a[k][0]=i;
        a[k][1]=i;
    }
    for (int i=1;i<=n;++i)
    {
        if (a[i][0])
        {
            if (a[i][0]>lastInd)
            {
                ++cur;
                largest=max(largest,cur);
            }
            else
                cur=1;
            lastInd=a[i][1];
        }
    }
    cout<<sz(s)-largest<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--) solve();
    return 0;
}