#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a2 array<int,2>
using namespace std;

void solve()
{
    int n,k=0,x;
    cin>>n;
    map<int,int> m;
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (m[x]==0)
            v.push_back(x);
        k=max(k,++m[x]);
    }
    priority_queue<a2> pq;
    for (int i : v)
        pq.push({m[i],i});
    a2 a,b;
    while (sz(pq)>1)
    {
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        n-=2;
        //cout<<a[1]<<" "<<b[1]<<"\n";
        if (--a[0]>0)
            pq.push(a);
        if (--b[0]>0)
            pq.push(b);
    }
    cout<<n<<"\n";
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