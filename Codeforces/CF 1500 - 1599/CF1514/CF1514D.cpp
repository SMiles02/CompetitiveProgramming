#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5+1;
vector<int> v[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,m,x,y,k,s,t;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    while (q--)
    {
        cin>>x>>y;
        s=1;
        for (int i=0;i<30;++i)
        {
            t=a[uniform_int_distribution<int>(x,y)(rng)];
            l=0;r=sz(v[t])-1;
            while (l<r)
            {
                m=l+(r-l)/2;
                if (v[t][m]<x)
                    l=m+1;
                else
                    r=m;
            }
            k=l;
            l=0;r=sz(v[t])-1;
            while (l<r)
            {
                m=l+(r-l)/2+1;
                if (y<v[t][m])
                    r=m-1;
                else
                    l=m;
            }
            s=max(s,l-k+1);
        }
        k=y-x+1;
        cout<<max(1,s*2-k)<<"\n";
    }
    return 0;
}