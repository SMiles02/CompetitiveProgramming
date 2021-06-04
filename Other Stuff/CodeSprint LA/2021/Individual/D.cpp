#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+2;
int n, a[N];
vector<int> v[N];

void print()
{
    int ans = 0;
    for (int i=1;i<n;++i)
        ans+=sz(v[i]);
    cout<<ans<<"\n";
    for (int i=1;i<n;++i)
        for (int j : v[i])
            cout<<j<<" ";
}

bool solve()
{
    for (int i=1;i<n;++i)
        v[i].clear();
    vector<int> w(n);
    iota(w.begin(), w.end(), 1);
    shuffle(w.begin(), w.end(), rng);
    ll s = 0;
    for (int i=0;i<n;++i)
    {
        s+=a[w[i]];
        v[a[w[i]]].push_back(w[i]);
        if (s%n==0)
        {
            print();
            return 1;
        }
        if (i>0&&!v[s%n].empty())
        {
            v[s%n].pop_back();
            print();
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]%=n;
        if (a[i]==0)
        {
            cout<<"1\n"<<i;
            return 0;
        }
    }
    while (1)
    {
        if (solve())
            return 0;
        //cout<<"tried\n";
    }
    return 0;
}