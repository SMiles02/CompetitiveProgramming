#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn = 2e5+7;
int bit[maxn];

void update(int i, int x)
{
    while (i<maxn)
    {
        bit[i]+=x;
        i+=(i&(-i));
    }
}

int query(int i)
{
    int x=0;
    while (i)
    {
        x+=bit[i];
        i-=(i&(-i));
    }
    return x;
}

int r_query(int l, int r)
{
    return query(r) - query(l-1);
}

vector<int> cur[26],final[26];
vector<pair<int,int>> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll ans=0;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        cur[(s[i]-'a')].push_back(i+1);
        final[(s[i]-'a')].push_back(n-i);
    }
    for (int i=0;i<26;++i)
    {
        k=sz(cur[i]);
        sort(cur[i].begin(), cur[i].end());
        sort(final[i].begin(), final[i].end());
        for (int j=0;j<k;++j)
            v.push_back({final[i][j],cur[i][j]});
    }
    sort(v.begin(), v.end());
    for (pii i : v)
    {
        ans+=r_query(i.s,maxn-1)+i.s-i.f;
        update(i.s,1);
    }
    cout<<ans;
    return 0;
}