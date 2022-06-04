#include <bits/stdc++.h>
using namespace std;

const int mn = 1e7+1;
int r[mn];
bitset<mn> comp;

void precalc()
{
    int c,x;
    for (int i=1;i<mn;++i)
        r[i]=1;
    for (int i=2;i<mn;++i)
        if (comp[i]==0)
            for (int j=i;j<mn;j+=i)
            {
                comp[j]=1;
                c=0;
                x=j;
                while (x%i==0)
                {
                    ++c;
                    x/=i;
                }
                if (c&1)
                    r[j]*=i;
            }
}

void solve()
{
    int n,x,ans=1,k;
    cin>>n>>x;
    set<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (s.count(r[k]))
        {
            ++ans;
            s.clear();
        }
        s.insert(r[k]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}