#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+7;
int pt[mn],rk[mn];
 
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
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n,k,fA=1,fB=1;
    cin>>n;
    make_set(n);
    vector<int> v;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        unite(k,i);
    }
    for (int i=1;i<=n;++i)
        if (find_set(i)==i)
            v.push_back(rk[i]);
    
    return 0;
}