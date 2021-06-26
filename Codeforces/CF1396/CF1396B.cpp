#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

priority_queue<int> q;

int turn(int p)
{
    if (p==0)
    {
        if (sz(q)==0)
            return -1;
    }
    if (q.top()>p)
    {
        if (p>0)
            q.push(p);
        p=q.top();
        q.pop();
    }
    return p-1;
}

void solve()
{
    int n,k,x=0,y=0;
    cin>>n;
    while (n--)
    {
        cin>>k;
        q.push(k);
    }
    for (int i=1;1;++i)
    {
        if (i&1)
        {
            x=turn(x);
            if (x==-1)
            {
                cout<<"HL\n";
                return;
            }
        }
        else
        {
            y=turn(y);
            if (y==-1)
            {
                cout<<"T\n";
                return;
            }
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