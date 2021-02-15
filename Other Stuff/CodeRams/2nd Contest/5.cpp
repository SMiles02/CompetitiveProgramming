#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+1;
int pt[mn],rk[mn];
bitset<mn> covid, positive;
 
int find_set(int v) {
    if (v == pt[v])
        return v;
    return pt[v] = find_set(pt[v]);
}
 
void make_set(int v) {
    for (int i=1;i<=v;++i)
    {
        pt[i] = i;
        rk[i] = 1;
    }
}
 
void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        pt[b] = a;
        rk[a] += rk[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y;
    cin>>n>>m>>k;
    make_set(n);
    while (m--)
    {
        cin>>x;
        for (int i=1;i<k;++i)
        {
            cin>>y;
            unite(x,y);
        }
    }
    cin>>x;
    while (x--)
    {
        cin>>y;
        positive[y]=1;
        covid[find_set(y)]=1;
    }
    vector<int> v;
    for (int i=1;i<=n;++i)
        if (covid[find_set(i)]&&!positive[i])
            v.push_back(i);
    cout<<sz(v)<<"\n";
    for (int i : v)
        cout<<i<<" ";
    return 0;
}