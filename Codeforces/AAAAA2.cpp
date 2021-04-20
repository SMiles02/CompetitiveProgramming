#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int firstDigit(int k)
{
    while (k>10)
        k/=10;
    return k;
}

void solve()
{
    int n,k,c=1,x,y,o=0;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> pq;
    while (n)
    {
        if (n%10)
            pq.push((n%10)*c);
        n/=10;
        c*=10;
    }
    while (sz(pq)+o<k)
    {
        x=pq.top();
        pq.pop();
        y=firstDigit(x);
        if (y>1)
        {
            for (int i=0;i<y;++i)
                pq.push(x/y);
        }
        else if (x==1)
            ++o;
        else
        {
            for (int i=0;i<10;++i)
                pq.push(x/10);
        }
    }
    while (o--)
        pq.push(1);
    while (sz(pq)>k)
    {
        x=pq.top();pq.pop();
        y=pq.top();pq.pop();
        pq.push(x+y);
    }
    while (!pq.empty())
    {
        x=pq.top();pq.pop();
        cout<<x<<" ";
    }
    cout<<"\n";
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