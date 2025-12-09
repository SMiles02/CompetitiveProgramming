#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int freq[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n-2];
    set<int> s;
    for (int i=0;i<n-2;++i)
    {
        cin>>a[i];
        ++freq[a[i]];
    }
    for (int i=1;i<=n;++i)
        if (!freq[i])
            s.insert(i);
    for (int i=0;i<n-2;++i)
    {
        cout<<*(s.begin())<<" "<<a[i]<<"\n";
        s.erase(s.begin());
        --freq[a[i]];
        if (!freq[a[i]])
            s.insert(a[i]);
    }
    cout<<*(s.begin())<<" "<<*(++s.begin())<<"\n";
    return 0;
}