#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int recurse(int x, int y,int round)
{
    x=(x-1)/2;
    y=(y-1)/2;
    if (x==y)
    {
        return round;
    }
    return recurse(x,y,round+1);      
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k,x,y;
    map<int,int> positions;
    cin>>n>>q;
    for (int i=n-1;i<(2*n-1);++i)
    {
        cin>>x;
        positions[x]=i;
    }
    while (q--)
    {
        cin>>k>>x>>y;
        if (k==1)
        {
            swap(positions[x],positions[y]);
        }
        else
        {
            cout<<recurse(positions[x],positions[y],1)<<"\n";
        }
    }
    return 0;
}