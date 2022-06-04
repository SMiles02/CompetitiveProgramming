#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e6+1;
bitset<mn> done;
int pre[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z;
    cin>>n>>x>>y;
    z=x+y;
    for (int i=1;i<mn;++i)
    {
        pre[i]+=pre[i-1];
        if (i-x>0)
            if (done[i-x])
                continue;
        if (i-y>0)
            if (done[i-y])
                continue;
        done[i]=1;
        ++pre[i];
    }
    cout<<pre[z]*(n/z)+pre[n%z];
    return 0;
}