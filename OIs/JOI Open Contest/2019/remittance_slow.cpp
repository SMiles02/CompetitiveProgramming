#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

// actually the AC version

const int N = 1e6+5;
int n, x, b[N][2];

bool solve(int k)
{
    for (int i=0;i<N*2;++i)
    {
        x=b[(k+i)%n][0]-b[(k+i)%n][1];
        if (x>0)
        {
            b[(k+i)%n][0]-=((x+(b[(k+i)%n][1]!=0))/2)*2;
            b[(k+i+1)%n][0]+=(x+(b[(k+i)%n][1]!=0))/2;
        }
    }
    for (int i=0;i<n;++i)
        if (b[i][0]!=b[i][1])
            return 0;
    return 1;
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>b[i][0]>>b[i][1];
    if (solve(0))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}