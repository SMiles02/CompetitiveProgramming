#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,ans=0,cur=0;
    cin>>n;
    vector<int> in;
    vector<int> out;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        in.push_back(a);
        out.push_back(b);
    }
    sort(in.rbegin(), in.rend());
    sort(out.rbegin(), out.rend());
    for (int i=0;i<n;++i)
    {
        while (sz(out)&&out.back()<in.back())
        {
            --cur;
            out.pop_back();
        }
        ++cur;
        in.pop_back();
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}