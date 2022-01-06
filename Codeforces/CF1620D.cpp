#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n,ans=INF,cur,tmp;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int j=0;j<3;++j)
        for (int k=0;k<3;++k)
        {
            cur=0;
            for (int i=0;i<n;++i)
            {
                tmp=INF;
                for (int l=0;l<=j;++l)
                    for (int m=0;m<=k;++m)
                        if (a[i]>=l+m*2&&(a[i]-l-m*2)%3==0)
                            tmp=min(tmp,(a[i]-l-m*2)/3);
                cur=max(cur,tmp);
            }
            ans=min(ans,cur+j+k);
        }
    cout<<ans<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}