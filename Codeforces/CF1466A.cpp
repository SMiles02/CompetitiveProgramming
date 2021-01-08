#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int a[n];
        set<int> s;
        for (int i=0;i<n;++i)
        {
            cin>>a[i];
            for (int j=0;j<i;++j)
                s.insert(a[i]-a[j]);
        }
        cout<<sz(s)<<"\n";
    }
    return 0;
}