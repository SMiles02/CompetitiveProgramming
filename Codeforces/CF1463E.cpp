#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 3e5+1;
int before[mn],after[mn],parent[mn],r[mn],chain[mn],hurdle[mn];
bitset<mn> done;
vector<int> ease[mn];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v)
{
    for (int i=1;i<=v;++i)
    {
        parent[i] = i;
        r[i] = 1;
    }
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        r[a] += r[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y;
    cin>>n>>k;
    int p[n+1];
    make_set(n);
    for (int i=1;i<=n;++i)
        cin>>p[i];
    while (k--)
    {
        cin>>x>>y;
        if (find_set(x)==find_set(y))
        {
            cout<<"0\n";
            return 0;
        }
        after[x]=y;
        before[y]=x;
        union_sets(x,y);
    }
    vector<int> v,ans;
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            v.clear();
            x=i;
            while (before[x]&&!done[x])
            {
                v.push_back(x);
                done[x]=1;
                x=before[x];
            }
            done[x]=1;
            if (!chain[x])
                chain[x]=x;
            for (int i : v)
                chain[i]=chain[x];
        }
    for (int i=1;i<=n;++i)
        if (p[i])
            if (chain[p[i]]!=chain[i])
            {
                ease[chain[p[i]]].push_back(chain[i]);
                ++hurdle[chain[i]];
            }
    queue<int> q;
    for (int i=1;i<=n;++i)
        if (i==chain[i]&&hurdle[i]==0)
            q.push(i);
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i : ease[x])
            if ((--hurdle[i])==0)
                q.push(i);
        while (1)
        {
            ans.push_back(x);
            if (!after[x])
                break;
            x=after[x];
        }
    }
    if (sz(ans)<n)
    {
        cout<<0;
        return 0;
    }
    set<int> s;
    s.insert(0);
    for (int i : ans)
    {
        if (s.find(p[i])==s.end())
        {
            cout<<0;
            return 0;
        }
        s.insert(i);
    }
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}