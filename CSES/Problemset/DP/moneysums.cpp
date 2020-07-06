#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int M=1000000;
int r[M+1];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    r[0]=1;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        for (int i=M;i>=k;--i)
            r[i]=max(r[i],r[i-k]);
    }
    vector<int> v;
    for (int i=1;i<=M;++i)
        if (r[i])
            v.push_back(i);
    cout<<sz(v)<<"\n";
    for (auto i : v)
        cout<<i<<" ";
    return 0;
}