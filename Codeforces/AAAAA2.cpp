#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1005;
int n, ans[N], cur, tot;
bitset<N> b;

void rec(int j, vector<int> v)
{
    if (j==n)
    {
        cur=0;
        for (int i=0;i<n;++i)
            b[i]=0;
        for (int i=0;i<n;++i)
            if (!b[i]&&!b[v[i]])
            {
                b[v[i]]=1;
                ++cur;
            }
        ++tot;
        ++ans[cur];
        return;
    }
    for (int i=0;i<n;++i)
        if (i!=j)
        {
            v.push_back(i);
            rec(j+1,v);
            v.pop_back();
        }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rec(0,{});
    cout<<tot<<"\n";
    for (int i=0;i<=n;++i)
        cout<<i<<": "<<ans[i]<<"\n";
    return 0;
}