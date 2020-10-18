#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bitset<201> dp,found;
map<int,int> m1,m2;

bool arePairable(int l, int r)
{
    if (m2[l]==0)
        if (m1[r]==0)
            if (((!found[l])&&(!found[r]))||((!found[l])&&m2[r]==-1)||((!found[r])&&m1[l]==-1)||(m1[l]==r&&m2[r]==l))
                return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    bool ok;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        m1[x]=y;
        m2[y]=x;
        if (x>0)
        {
            if (found[x])
            {
                cout<<"No";
                return 0;
            }
            found[x]=1;
        }
        if (y>0)
        {
            if (found[y])
            {
                cout<<"No";
                return 0;
            }
            found[y]=1;
        }
        if (x>0&&y>0)
            if (x>y)
            {
                cout<<"No";
                return 0;
            }
    }
    n*=2;
    dp[0]=1;
    for (int i=2;i<=n;i+=2)
        for (int j=1;i-(2*j)>=0;++j)
            if (dp[i-(2*j)])
            {
                ok=1;
                for (int k=i-(2*j)+1;k<=i-j;++k)
                    if (!arePairable(k,k+j))
                        ok=0;
                if (ok)
                    dp[i]=1;
            }
    if (dp[n])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}