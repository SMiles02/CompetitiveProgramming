#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> divisors[1000001];
int done[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans=0;
    for (int i=1;i<1000001;++i)
    {
        for (int j=(i << 1);j<1000001;j+=i)
            divisors[j].push_back(i);
    }
    int n;
    bool b;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++done[a[i]];
    }
    for (int i=0;i<n;++i)
    {
        if (done[a[i]]>1)
            continue;
        b=1;
        for (auto x : divisors[a[i]])
            if (done[x])
            {
                b=0;
                break;
            }
        if (b)
            ++ans;
    }
    cout<<ans;
    return 0;
}