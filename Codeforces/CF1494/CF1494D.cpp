#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a3 array<int,3>
using namespace std;

const int mn = 2000;
int pt[mn],rk[mn],rt[mn];
 
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
        rt[i] = i;
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
    int n,x,y;
    cin>>n;
    int a[mn],p[mn];
    make_set(mn-5);
    priority_queue<a3,vector<a3>,greater<a3>> pq;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            cin>>x;
            if (i==j)
            {
                a[i]=x;
                continue;
            }
            pq.push({x,i,j});
        }
    a3 b;
    while (!pq.empty())
    {
        b=pq.top();
        pq.pop();
        x=find_set(b[1]);
        y=find_set(b[2]);
        if (x==y)
            continue;
        if (a[rt[x]]==b[0])
        {
            p[rt[y]]=rt[x];
            unite(b[1],b[2]);
            continue;
        }
        if (a[rt[y]]==b[0])
        {
            p[rt[x]]=rt[y];
            unite(b[1],b[2]);
            continue;
        }
        p[rt[x]]=p[rt[y]]=++n;
        unite(b[1],b[2]);
        rt[find_set(b[1])]=n;
        a[n]=b[0];
    }
    cout<<n<<"\n";
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
    cout<<n<<"\n";
    for (int i=1;i<n;++i)
        cout<<i<<" "<<p[i]<<"\n";
    return 0;
}