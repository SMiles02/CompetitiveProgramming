#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k;
    set<int> s;
    priority_queue<int> pq;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        pq.push(k);
    }
    while (n--)
    {
        k=pq.top();pq.pop();
        if (s.find(k+1)==s.end())
            s.insert(k+1);
        else
            s.insert(k);
    }
    cout<<sz(s)<<"\n";
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