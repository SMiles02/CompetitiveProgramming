#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+69;
int pt[N], rk[N], val[N], m[N];
 
int find_set(int v) {
    if (v == pt[v]) return v;
    return pt[v] = find_set(pt[v]);
}
 
int unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b]) swap(a, b);
        pt[b] = a;
        rk[a] += rk[b];
    }
    return a;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cur=0, t, x, y;
    cin>>n;
    vector<int> v;
    while (n--)
    {
        cin>>t>>x;
        if (t==1)
        {
            v.push_back(++cur);
            pt[cur]=cur;
            rk[cur]=1;
            if (m[x])
                m[x]=unite(m[x],cur);
            else
                m[x]=cur;
            val[m[x]]=x;
        }
        else
        {
            cin>>y;
            if (x==y)
                continue;
            if (m[x])
            {
                if (m[y])
                    m[y]=unite(m[x], m[y]);
                else
                    m[y]=find_set(m[x]);
                val[m[y]]=y;
            }
            m[x]=0;
        }
    }
    for (int i : v)
        cout<<val[find_set(i)]<<" ";
    return 0;
}