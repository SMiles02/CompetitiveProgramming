#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,x;
    ll s=0,t=0;
    cin>>n;
    deque<int> a,b;
    priority_queue<int> r;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        a.push_back(x);
        s+=x;
    }
    for (int i=0;i<n;++i)
    {
        cin>>x;
        b.push_back(x);
        t+=x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0;i<n/4;++i)
    {
        s-=a[0];
        a.pop_front();
    }
    for (int i=0;i<n/4;++i)
    {
        t-=b[0];
        r.push(b[0]);
        b.pop_front();
    }
    if (s>=t)
    {
        cout<<"0\n";
        return;
    }
    for (int i=1;;++i)
    {
        s+=100;
        a.push_back(100);
        b.push_front(0);
        if (!r.empty()&&0<r.top())
        {
            x=r.top();
            t+=x;
            r.pop();
            r.push(0);
            b.pop_front();
            b.push_front(x);
        }
        if ((n+i)%4==0)
        {
            s-=a.front();
            t-=b.front();
            r.push(b.front());
            a.pop_front();
            b.pop_front();
        }
        if (s>=t)
        {
            cout<<i<<"\n";
            return;
        }
    }
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