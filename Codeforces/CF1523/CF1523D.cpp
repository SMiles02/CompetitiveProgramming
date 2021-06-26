#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,p,k,tmp;
    cin>>n>>m>>p;
    char c;
    vector<ll> a(n,0);
    ll cur;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            cin>>c;
            if (c=='1')
                a[i]+=1LL<<j;
        }
    pair<int,ll> ans = {0,0};
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);
    for (int iter=0;iter<min(50,n);++iter)
    {
        cur=a[order[iter]];
        vector<int> bits;
        for (int i=0;i<m;++i)
            if (cur&(1LL<<i))
                bits.push_back(i);
        k=bits.size();
        vector<int> v(1<<k,0);
        for (int i=0;i<n;++i)
        {
            tmp=0;
            for (int j=0;j<k;++j)
                if (a[i]&(1LL<<bits[j]))
                    tmp^=1<<j;
            ++v[tmp];
        }
        for (int j=0;j<k;++j)
            for (int i=0;i<(1<<k);++i)
                if (i&(1<<j))
                    v[i^(1<<j)]+=v[i];
        for (int i=0;i<(1<<k);++i)
            if (v[i]*2>=n&&__builtin_popcount(i)>ans.first)
            {
                ans={__builtin_popcount(i),0};
                for (int j=0;j<k;++j)
                    if (i&(1<<j))
                        ans.second^=1LL<<bits[j];
            }
    }
    for (int i=0;i<m;++i)
    {
        if (ans.second&(1LL<<i))
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}