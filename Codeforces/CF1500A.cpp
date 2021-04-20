#include <bits/stdc++.h>
using namespace std;

vector<array<int,2>> sm[5000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
        {
            for (auto k : sm[a[i]+a[j]])
                if (k[0]!=i&&k[1]!=i&&k[0]!=j&&k[1]!=j)
                {
                    cout<<"YES\n"<<i+1<<" "<<j+1<<" "<<k[0]+1<<" "<<k[1]+1<<"\n";
                    return 0;
                }
            sm[a[i]+a[j]].push_back({i,j});
        }
    cout<<"NO\n";
    return 0;
}