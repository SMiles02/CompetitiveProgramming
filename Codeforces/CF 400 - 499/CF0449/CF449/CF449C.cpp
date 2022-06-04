#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
bitset<N> used, p;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n;
    vector<array<int,2>> ans;
    for (int i=2;i<=n;++i)
        if (!p[i])
            for (int j=i*2;j<=n;j+=i)
                p[j]=1;
    for (int i=n/2;i>1;--i)
        if (!p[i])
        {
            x=i;
            for (int j=i*3;j<=n;j+=i)
                if (!used[j])
                {
                    used[j]=1;
                    if (x)
                    {
                        ans.push_back({x,j});
                        x=0;
                    }
                    else
                        x=j;
                }
            if (x)
            {
                ans.push_back({i*2,x});
                used[i*2]=1;
            }
        }
    cout<<ans.size()<<"\n";
    for (auto i : ans)
        cout<<i[0]<<" "<<i[1]<<"\n";
    return 0;
}