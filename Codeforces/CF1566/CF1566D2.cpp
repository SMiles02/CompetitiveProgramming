#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int n,a[N],b[N],c[N];
 
int find_inversions(int l, int r)
{
    if (l==r)
        return 0;
    int m=l+((r-l)>>1),x=l,y=m+1,ans=find_inversions(l,m)+find_inversions(m+1,r);
    for (int i=l;i<=r;++i)
    {
        if (x>m)
            c[i]=b[y++];
        else if (y>r)
            c[i]=b[x++];
        else if (b[x]>b[y])
        {
            c[i]=b[y++];
            ans+=m-x+1;
        }
        else
            c[i]=b[x++];
    }
    for (int i=l;i<=r;++i)
        b[i]=c[i];
    return ans;
}

void solve()
{
    int n,m,x,y,ans=0;
    cin>>n>>m;
    set<int> s;
    map<int,deque<int>> mp;
    for (int i=0;i<n*m;++i)
    {
        cin>>x;
        s.insert(x);
        mp[x].push_back(i);
    }
    y=0;
    vector<int> v;
    for (int i : s)
        while (!mp[i].empty())
        {
            while (!mp[i].empty()&&y+v.size()<m)
            {
                v.push_back(mp[i][0]);
                mp[i].pop_front();
            }
            while (!v.empty())
            {
                b[y++]=v.back();
                v.pop_back();
            }
            if (y==m)
            {
                for (int i=0;i<m;++i)
                    b[i]*=-1;
                ans+=find_inversions(0,m-1);
                y=0;
            }
        }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}