#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w,h,k,x;
    cin>>w>>h;
    vector<vector<int>> v(4);
    for (int i=0;i<4;++i)
    {
        cin>>k;
        while (k--)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    cout<<max(1LL*h*max(v[0].back()-v[0][0],v[1].back()-v[1][0]),1LL*w*max(v[2].back()-v[2][0],v[3].back()-v[3][0]))<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}