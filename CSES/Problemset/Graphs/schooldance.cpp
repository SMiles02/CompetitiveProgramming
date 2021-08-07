#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
const int N = 1005;
int mt[N];
vector<int> e[N];
bitset<N> done;
 
bool try_kuhn(int c)
{
    if (done[c])
        return 0;
    done[c]=1;
    for (int i : e[c])
        if (!mt[i]||try_kuhn(mt[i]))
        {
            mt[i] = c;
            return 1;
        }
    return 0;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y,ans=0;
    cin>>n>>m>>k;
    while (k--)
    {
        cin>>x>>y;
        e[x].push_back(n+y);
        e[n+y].push_back(x);
    }
    for (int i=1;i<=n;++i)
    {
        done.reset();
        try_kuhn(i);
    }
    for (int i=n+1;i<=n+m;++i)
        ans+=(mt[i]!=0);
    cout<<ans<<"\n";
    for (int i=n+1;i<=n+m;++i)
        if (mt[i])
            cout<<mt[i]<<" "<<i-n<<"\n";
    return 0;
}