#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    long long s=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    while (n--)
    {
        cin>>k;
        if (s+k>=0)
        {
            s+=k;
            pq.push(k);
        }
        else if (k>pq.top())
        {
            s-=pq.top();
            pq.pop();
            s+=k;
            pq.push(k);
        }
    }
    cout<<pq.size()-1;
    return 0;
}