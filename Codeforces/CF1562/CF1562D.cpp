#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void print(vector<int> v)
{
    cout<<sz(v)<<"\n";
    for (int i : v)
        cout<<i<<" ";
    cout<<"\n";
}

const int N = 3e5+6;
int p[N];

void solve()
{
    int n,q,l,r;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> v(n);
    map<int,set<int>> ms;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='+')
            v[i]=1;
        else
            v[i]=-1;
    }
    for (int i=1;i<=n;++i)
    {
        if (i&1)
            p[i]=p[i-1]+v[i-1];
        else
            p[i]=p[i-1]-v[i-1];
        ms[p[i]].insert(i);
    }
    while (q--)
    {
        cin>>l>>r;
        vector<int> w;
        if ((l&1)!=(r&1))
        {
            if (p[r]-p[l-1]==0)
            {
                print(w);
                continue;
            }
            w.push_back(l++);
        }
        if (p[r]-p[l-1]>0)
            w.push_back(*(ms[p[l-1]+(p[r]-p[l-1])/2+1]).lower_bound(l));
        else
            w.push_back(*(ms[p[l-1]+(p[r]-p[l-1])/2-1]).lower_bound(l));
        print(w);
    }
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