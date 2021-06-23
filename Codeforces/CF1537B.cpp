#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll d(int a, int b, int c, int d)
{
    return abs(a-c)+abs(b-d);
}

void solve()
{
    int n,m,x,y,a1,a2,a3,a4;
    ll mx = -1;
    cin>>n>>m>>x>>y;
    vector<array<int,2>> v;
    v.push_back({1,1});
    v.push_back({1,m});
    v.push_back({n,1});
    v.push_back({n,m});
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            if (d(x,y,v[i][0],v[i][1])+d(x,y,v[j][0],v[j][1])+d(v[i][0],v[i][1],v[j][0],v[j][1])>mx)
            {
                mx=d(x,y,v[i][0],v[i][1])+d(x,y,v[j][0],v[j][1])+d(v[i][0],v[i][1],v[j][0],v[j][1]);
                a1=v[i][0];
                a2=v[i][1];
                a3=v[j][0];
                a4=v[j][1];
            }
    cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<"\n";
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