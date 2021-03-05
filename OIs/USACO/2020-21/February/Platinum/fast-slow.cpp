#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+4, INF = 1e9+7;
int n,a[N],seg[N<<2];
vector<int> s[N];

int f(int l, int r)
{
    if (l>r)
        return 0;
    int rtn = 1, mn=INF,lt=l-1;
    for (int i=l;i<=r;++i)
        mn=min(mn,a[i]);
    for (int i=l;i<=r;++i)
        if (a[i]==mn)
        {
            rtn+=f(lt+1,i-1);
            lt=i;
        }
    return rtn+f(lt+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    freopen("fast-slow.out","w",stdout);
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        cout<<f(x,y)<<"\n";
    }
    return 0;
}