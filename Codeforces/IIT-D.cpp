#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int done[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,x;
    queue<int> q;
    q.push(1);
    while (sz(q))
    {
        x=q.front();
        q.pop();
        if (x>1000000)
            continue;
        if (x+1<1000001&&!done[x+1])
        {
            q.push(x+1);
            done[x+1]=x;
        }
        if (x*2<1000001&&!done[x*2])
        {
            q.push(x*2);
            done[x*2]=x;
        }
        if (x*3<1000001&&!done[x*3])
        {
            q.push(x*3);
            done[x*3]=x;
        }
    }
    cin>>t;
    vector<int> v;
    while (t--)
    {
        cin>>n;
        while (n>1)
        {
            v.push_back(n);
            n=done[n];
        }
        cout<<sz(v)+1<<"\n";
        cout<<"1 ";
        while (sz(v))
        {
            cout<<v.back()<<" ";
            v.pop_back();
        }
        cout<<"\n";
    }
    return 0;
}